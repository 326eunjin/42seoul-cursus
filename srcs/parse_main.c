/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:48:02 by ejang             #+#    #+#             */
/*   Updated: 2022/08/20 17:36:05 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../inc/cub3d.h"
#include "../inc/get_next_line.h"
#include "../libft/libft.h"

void	remove_new_line(char **line)
{
	int		len;
	char	*tmp;

	len = ft_strlen(*line);
	if ((*line)[len - 1] == '\n')
	{
		tmp = ft_strdup(*line);
		free(*line);
		(*line) = ft_substr(tmp, 0, len - 1);
		free(tmp);
	}
	return ;
}

int	set_elements(char **line, char ***split_line, t_map *map)
{
	*split_line = ft_split(*line, ' ');
	if (ft_strncmp((*split_line)[0], "NO", ft_strlen("NO")) \
		== 0 && map->no == NULL)
		map->no = ft_strdup((*split_line)[1]);
	else if (ft_strncmp((*split_line)[0], "SO", ft_strlen("SO")) \
		== 0 && map->so == NULL)
		map->so = ft_strdup((*split_line)[1]);
	else if (ft_strncmp((*split_line)[0], "WE", ft_strlen("WE")) \
		== 0 && map->we == NULL)
		map->we = ft_strdup((*split_line)[1]);
	else if (ft_strncmp((*split_line)[0], "EA", ft_strlen("EA")) \
		== 0 && map->ea == NULL)
		map->ea = ft_strdup((*split_line)[1]);
	else if (ft_strncmp((*split_line)[0], "C", ft_strlen("C")) \
		== 0 && map->c == NULL)
		map->c = ft_strdup((*split_line)[1]);
	else if (ft_strncmp((*split_line)[0], "F", ft_strlen("F")) \
		== 0 && map->f == NULL)
		map->f = ft_strdup((*split_line)[1]);
	else
		return (1);
	return (0);
}

void	check_elements(int fd, t_map *map)
{
	char	**split_line;
	char	*line;

	line = get_next_line(fd);
	if (ft_strncmp(line, "\n", ft_strlen("\n")) == 0 || is_space_line(&line) == 0)
		return (free(line));
	if (get_count(line, ' ') != 2)
	{
		free(line);
		print_error("INVALID MAP");
	}
	if (set_elements(&line, &split_line, map) == 0)
	{
		free(line);
		free_split(split_line);
	}
	else
	{
		free(line);
		free_split(split_line);
		print_error("INVALID MAP");
	}
}

void	parse_map_info(int fd, unsigned int *map_loc, t_map *map)
{
	*map_loc = 1;
	check_elements(fd, map);
	while (map->no == NULL || map->so == NULL || map->we == NULL || \
		map->ea == NULL || map->c == NULL || map->f == NULL)
	{
		check_elements(fd, map);
		(*map_loc)++;
	}
}

void	parse_main(t_map *map, char *file_name)
{
	int				fd;
	unsigned int	map_loc;
	int				i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error("File open failed\n");
	parse_map_info(fd, &map_loc, map);
	parse_map_size(fd, &map_loc, &(map->map_height), &(map->map_width));
	map->map = (char **)malloc(sizeof (char *) * map->map_height);
	if (map->map == NULL)
		print_error("Memory allocation failed");
	i = 0;
	while (i < (int)map->map_height)
	{
		map->map[i] = (char *)malloc(sizeof(char) * map->map_width);
		if (map->map[i] == NULL)
			print_error("Memory allocation failed");
		i++;
	}
	map_content(file_name, map, map_loc);
}
