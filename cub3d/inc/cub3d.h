/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:17:23 by jeyoon            #+#    #+#             */
/*   Updated: 2022/08/31 16:14:31 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_WIDTH 600
# define SCREEN_HEIGHT 480
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define KEYPRESS 2
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define X_EVENT_KEY_EXIT   17
# define KEY_ESC			53

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f_color;
	int		c_color;
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

typedef struct s_cub
{
	t_mlx	*mlx;
	t_map	*map;
	t_info	*info;
}	t_cub;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
}	t_ray;

typedef struct s_draw
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	tex_num;
	int	tex_x;
}	t_draw;
/*
	ANCHOR init.c
*/
void			init_struct(t_cub *cub);
void			mlx_struct_init(t_cub *cub);

/*
	ANCHOR parse_main.c parse_map.c
*/
void			parse_main(t_cub *cub, char *file_name);
int				is_space_line(char **line);
void			remove_new_line(char **line);
void			parse_map_size(int fd, unsigned int *map_loc, t_cub *cub);
void			map_content(char *file_name, \
	t_cub *cub, unsigned int map_loc);
unsigned int	cal_color(char *str, t_cub *cub);
char			*chop_space(char *str);
int				is_space_in_str(char *str);
int				is_nswe(char *first_element);
/*
	ANCHOR raycasting_*.c
*/
void			init_ray(t_ray *ray, t_cub *cub, int x);
void			dda(t_ray *ray, t_cub *cub);
void			cal_ray(t_ray *ray, t_cub *cub, t_draw *draw);
void			draw_line(t_cub *cub, t_draw draw, int x);
int				main_loop(t_cub *cub);

/*
	ANCHOR key_press.c
*/
int				key_press(int keycode, t_cub *cub);
int				press_x_button(t_cub *cub);

/*
	ANCHOR utils
*/
void			print_error(char *msg, t_cub *cub);
void			free_split(char **tmp);
void			pass_empty_line(int fd, char **line, unsigned int *map_loc);
int				pass_empty_line_map(int fd, char **line);

/*
	ANCHOR check_map.c
*/
void			check_map(t_cub *cub);

/*
	ANCHOR free.c
*/
void			free_map(t_cub *cub);
void			free_mlx(t_cub *cub);

#endif