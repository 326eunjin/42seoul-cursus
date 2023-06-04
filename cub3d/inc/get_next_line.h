/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:07:14 by jeyoon            #+#    #+#             */
/*   Updated: 2022/08/19 20:54:28 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*cut_line(char **backup, char **buffer, int cut_idx);
int		is_newline(char *str);
char	*mem_free(char	**backup, char **buffer);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_strndup(char *str, int n);

#endif
