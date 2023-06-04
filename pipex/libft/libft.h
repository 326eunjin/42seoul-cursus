/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:35:02 by ejang             #+#    #+#             */
/*   Updated: 2022/03/31 07:05:29 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t dstsize);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char *s1, char *s2);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strnstr(const char *big,
						const char *little, size_t len);

#endif
