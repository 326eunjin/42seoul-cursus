/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:42:49 by ejang             #+#    #+#             */
/*   Updated: 2022/01/22 02:59:00 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);
char		*get_next_line(int fd);

#endif