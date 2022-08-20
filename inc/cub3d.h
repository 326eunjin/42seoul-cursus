/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:17:23 by jeyoon            #+#    #+#             */
/*   Updated: 2022/08/20 16:37:44 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
	int		map_height;
	int		map_width;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		**buf;
	int		*texture[4];
	//int		texture[4][tex_height * tex_width];
	t_img	img;
}	t_mlx;

typedef struct s_info
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_info;

/*
	ANCHOR map
*/

void	parse_main(t_map *map, char *file_name);
void	parse_map_size(int fd, \
	unsigned int *map_loc, int *max_width, int *max_height);
void	map_content(char *file_name, \
	t_map *map, unsigned int map_loc);
void	remove_new_line(char **line);
void	pass_empty_line(int fd, char **line, unsigned int *map_loc);

/*
	ANCHOR utils
*/

void	print_error(char *msg);
void	free_split(char **tmp);

#endif