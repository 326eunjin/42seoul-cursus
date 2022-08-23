/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:48:02 by ejang             #+#    #+#             */
/*   Updated: 2022/08/23 17:15:23 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../inc/cub3d.h"
#include "../inc/get_next_line.h"
#include "../libft/libft.h"

void	remove_new_line(char **line)
{
	unsigned int	len;
	char			*tmp;

	if (*line == NULL)
		return ;
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

int	set_elements(char **line, char ***split_line, t_cub *cub)
{
	*split_line = ft_split(*line, ' ');
	if (ft_strncmp((*split_line)[0], "NO", ft_strlen("NO")) \
		== 0 && cub->map->no == NULL)
		cub->map->no = ft_strdup((*split_line)[1]);
	else if (ft_strncmp((*split_line)[0], "SO", ft_strlen("SO")) \
		== 0 && cub->map->so == NULL)
		cub->map->so = ft_strdup((*split_line)[1]);
	else if (ft_strncmp((*split_line)[0], "WE", ft_strlen("WE")) \
		== 0 && cub->map->we == NULL)
		cub->map->we = ft_strdup((*split_line)[1]);
	else if (ft_strncmp((*split_line)[0], "EA", ft_strlen("EA")) \
		== 0 && cub->map->ea == NULL)
		cub->map->ea = ft_strdup((*split_line)[1]);
	else if (ft_strncmp((*split_line)[0], "C", ft_strlen("C")) \
		== 0 && cub->map->c == NULL)
		cub->map->c = ft_strdup((*split_line)[1]);
	else if (ft_strncmp((*split_line)[0], "F", ft_strlen("F")) \
		== 0 && cub->map->f == NULL)
		cub->map->f = ft_strdup((*split_line)[1]);
	else
		return (1);
	return (0);
}

void	check_elements(int fd, t_cub *cub)
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
	if (set_elements(&line, &split_line, cub) == 0)
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

void	parse_map_info(int fd, unsigned int *map_loc, t_cub *cub)
{
	*map_loc = 1;
	check_elements(fd, cub);
	while (cub->map->no == NULL || cub->map->so == NULL || cub->map->we \
		== NULL || cub->map->ea == NULL || cub->map->c == NULL \
		|| cub->map->f == NULL)
	{
		check_elements(fd, cub);
		(*map_loc)++;
	}
}

void	parse_main(t_cub *cub, char *file)
{
	int				fd;
	unsigned int	map_loc;
	int				i;

	if (ft_strlen(file) < 4 || !(file[ft_strlen(file) - 4] == '.' \
		&& file[ft_strlen(file) - 3] == 'c' && file[ft_strlen(file) - 2] == 'u' \
			&& file[ft_strlen(file) - 1] == 'b'))
		print_error("Wrong file name");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("File open failed");
	parse_map_info(fd, &map_loc, cub);
	parse_map_size(fd, &map_loc, cub);
	cub->map->map = (char **)malloc(sizeof (char *) * cub->map->map_height);
	if (cub->map->map == NULL)
		print_error("Memory allocation failed");
	i = 0;
	while (i < (int)cub->map->map_height)
	{
		cub->map->map[i] = (char *)malloc(sizeof(char) * cub->map->map_width);
		if (cub->map->map[i] == NULL)
			print_error("Memory allocation failed");
		i++;
	}
	map_content(file, cub, map_loc);
}
