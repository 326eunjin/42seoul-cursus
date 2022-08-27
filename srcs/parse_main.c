/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:48:02 by ejang             #+#    #+#             */
/*   Updated: 2022/08/27 15:57:53 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../inc/cub3d.h"
#include "../inc/get_next_line.h"
#include "../libft/libft.h"

int	set_elements(char **line, char ***split_line, t_cub *cub)
{
	char	*first_element;

	first_element = (*split_line)[0];
	if (ft_strncmp(first_element, "NO", ft_strlen(first_element)) \
		== 0 && cub->map->no == NULL)
		cub->map->no = ft_strdup((*split_line)[1]);
	else if (ft_strncmp(first_element, "SO", ft_strlen(first_element)) \
		== 0 && cub->map->so == NULL)
		cub->map->so = ft_strdup((*split_line)[1]);
	else if (ft_strncmp(first_element, "WE", ft_strlen(first_element)) \
		== 0 && cub->map->we == NULL)
		cub->map->we = ft_strdup((*split_line)[1]);
	else if (ft_strncmp(first_element, "EA", ft_strlen(first_element)) \
		== 0 && cub->map->ea == NULL)
		cub->map->ea = ft_strdup((*split_line)[1]);
	else if (ft_strncmp(first_element, "C", ft_strlen(first_element)) \
		== 0 && cub->map->c_color == -1)
		cub->map->c_color = cal_color(*line);
		//cub->map->c = ft_strdup(*line);//c 빼고 그 이후부터 넣을 수 있는 방법?
	else if (ft_strncmp(first_element, "F", ft_strlen(first_element)) \
		== 0 && cub->map->f_color == -1)
		cub->map->f_color = cal_color(*line);
		// cub->map->f = ft_strdup((*split_line)[1]);
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
	split_line = ft_split(line, ' ');
	if (ft_strncmp(split_line[0],"NO",2) == 0 || ft_strncmp(split_line[0],"SO",2) == 0 || ft_strncmp(split_line[0],"WE",2) == 0|| ft_strncmp(split_line[0],"EA",2) == 0)
		if (get_count(line, ' ') != 2 )
		{
			free(line);
			free_split(split_line);
			print_error("INVALID TEXTURE");
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
		print_error("INVALID ARGUMENT");
	}
}

void	parse_map_info(int fd, unsigned int *map_loc, t_cub *cub)
{
	*map_loc = 1;
	check_elements(fd, cub);
	while (cub->map->no == NULL || cub->map->so == NULL || cub->map->we \
		== NULL || cub->map->ea == NULL || cub->map->c_color == -1 \
		|| cub->map->f_color == -1)
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
