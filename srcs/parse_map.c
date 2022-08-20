/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:54:17 by jeyoon            #+#    #+#             */
/*   Updated: 2022/08/20 16:35:02 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../inc/cub3d.h"
#include "../inc/get_next_line.h"
#include "../libft/libft.h"

#include <stdio.h>

int	is_space_line(char **line)
{
	unsigned int	i;

	remove_new_line(line);
	i = 0;
	while (i < ft_strlen(*line))
	{
		if ((*line)[(int)i] != ' ')
			return (1); // space 외의 문자가 있음
		i++;
	}
	return (0);	// space 외의 문자가 없음
}

void	pass_empty_line(int fd, char **line, unsigned int *map_loc)
{
	*line = get_next_line(fd);
	// 읽기 실패하지 않고, 개행만 있거나, 공백만 있는 문자열의 경우, map_loc 증가시키고 다시 읽는다.
	while (*line != NULL && (ft_strncmp(*line, "\n", ft_strlen("\n")) == 0 \
		|| is_space_line(line) == 0))
	{
		*map_loc = *map_loc + 1;
		free(*line);
		*line = get_next_line(fd);
	}
}

void	parse_map_size(int fd, unsigned int *map_loc, \
	int *max_height, int *max_width)
{
	char	*line;

	pass_empty_line(fd, &line, map_loc);
	if (line == NULL)
	{
		close(fd);
		print_error("Missing map content\n");
	}
	while (line != NULL)
	{
		*max_height = *max_height + 1;
		if (*max_width < (int)ft_strlen(line))
			*max_width = (int)ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	fill_map(char *line, int fd, t_map *map)
{
	int	h;
	int	w;

	h = 0;
	while (line != NULL)
	{
		w = 0;
		while (w < (int)ft_strlen(line))
		{
			map->map[h][w] = line[w];
			w++;
		}
		while (w < map->map_width)
		{
			map->map[h][w] = ' ';
			w++;
		}
		free(line);
		line = get_next_line(fd);
		h++;
	}
}

void	map_content(char *file_name, \
	t_map *map, unsigned int map_loc)
{
	unsigned int	i;
	int				fd;
	char			*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		print_error("File open failed\n");
		return ;
	}
	line = get_next_line(fd);
	while (line != NULL && i != map_loc)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line == NULL)
		print_error("Memory allocation failed");
	fill_map(line, fd, map);
	close(fd);
}
