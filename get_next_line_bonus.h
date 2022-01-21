/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:42:40 by ejang             #+#    #+#             */
/*   Updated: 2022/01/19 02:26:50 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);

#endif