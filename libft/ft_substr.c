/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:06:25 by ejang             #+#    #+#             */
/*   Updated: 2022/06/15 13:21:26 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	substr_len;
	size_t	length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (length <= start)
		return (ft_strdup(""));
	substr_len = len;
	if (start + len > length)
		substr_len = length - start;
	ptr = (char *)malloc(sizeof(char) * (substr_len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)s + start, substr_len + 1);
	return (ptr);
}
