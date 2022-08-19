/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:48:02 by ejang             #+#    #+#             */
/*   Updated: 2022/08/19 17:38:00 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <fcntl.h>
#include "../inc/get_next_line.h"

void	print_error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void	parse_map_info(unsigned int *map_loc)
{
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd));
	}
}

void	parse_map_size(unsigned int *map_loc)
{

}

void	map_content()
{

}

void	parse_main(t_map *map, t_info *info, char *file_name)
{
	int				fd;
	unsigned int	map_loc;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error("Open failed");
	// line = get_next_line(fd);
	// while (line != NULL)
	// {
	// 	line = get_next_line(fd));
	// }
	parse_map_info(fd, &map_loc);
	parse_map_size();
	// malloc
	map_content();

}
