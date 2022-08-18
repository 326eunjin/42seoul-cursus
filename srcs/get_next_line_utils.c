/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:07:12 by jeyoon            #+#    #+#             */
/*   Updated: 2021/10/28 18:43:08 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strndup(s1, ft_strlen(s1)));
	if (!s1 && s2)
		return (ft_strndup(s2, ft_strlen(s2)));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = (char *)malloc(s1_len + s2_len + 1);
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, s1, s1_len + 1);
	ft_strlcpy(temp + s1_len, s2, s2_len + 1);
	free(s1);
	s1 = 0;
	return (temp);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strndup(char *str, int n)
{
	char	*new_string;
	int		i;

	i = 0;
	new_string = (char *)malloc(n + 1);
	if (!new_string)
		return (NULL);
	while (i < n)
	{
		new_string[i] = str[i];
		i++;
	}
	new_string[n] = '\0';
	return (new_string);
}
