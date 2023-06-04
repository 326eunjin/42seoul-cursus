/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeukim <yeukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:39:05 by yeukim            #+#    #+#             */
/*   Updated: 2021/04/15 12:18:24 by yeukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define ERROR "map error\n"

typedef	struct	s_map
{
	int		**int_map;
	char	*str;

	int		line_size;
	int		line_num;
	int		line_input;

	int		max;
	int		max_col;
	int		max_row;

	char	map_char[3];
}				t_map;

void			ft_run(t_map *map_s, int index);

void			ft_first_line(t_map *map_s, char *file_name);
void			ft_first_line2(t_map *map_s, int fd, char *buf, int *i);
void			ft_second_line(t_map *map_s, int fd, char *free_buf);
int				ft_total_size(t_map *map_s, char *file_name);
void			ft_total_str(t_map *map_s, char *file_name);

int				ft_first_stdin(t_map *map_s);
void			ft_first_stdin2(t_map *map_s, char *buf, int i);
void			ft_total_stdin(t_map *map_s);
char			*ft_expand_buf(t_map *map_s, char *buf, unsigned int *buf_size);

void			split_line(t_map *map_s);
void			split_line2(t_map *map_s, char **str_cp, int *obstacle, int *i);
void			malloc_line(t_map *map_s);
int				count_line(t_map *map_s);
void			ft_split(t_map *map_s);

void			ft_line_check(t_map *map_s, char *buf);
int				ft_map_check(t_map *map_s, char ch);
int				ft_map_char_check(t_map *map_s);

void			ft_init(t_map *map_s);
void			ft_map_init(t_map *map_s);
int				ft_min(t_map *map_s, int row, int col);
void			ft_find_max(t_map *map_s);
void			ft_solve(t_map *map_s);

void			ft_bsq(t_map *map_s);
void			ft_print_map(t_map *map_s);

void			ft_memory_free(t_map *map_s, int index);
void			ft_file_error(t_map *map_s, int fd, char *buf);
void			ft_stdin_error(t_map *map_s, char *buf);
void			ft_split_error(t_map *map_s, int index);

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
void			ft_strncpy(char *dest, char *src, unsigned int n);

#endif
