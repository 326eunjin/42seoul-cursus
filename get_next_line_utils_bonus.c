/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:42:42 by ejang             #+#    #+#             */
/*   Updated: 2022/01/19 02:02:16 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static	char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strdup(const char *str)
{
	int		len;
	char	*ptr;

	len = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	ft_strcpy(ptr, (char *)str);
	return (ptr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	if (dest == 0 || src == 0)
		return (0);
	while (src[count] != '\0')
		count++;
	while ((i + 1 < dstsize) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dest[i] = '\0';
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*ptr;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = (char *)malloc(len1 + len2 + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len1 + 1);
	ft_strlcpy(ptr + len1, s2, len2 + 1);
	return (ptr);
}
