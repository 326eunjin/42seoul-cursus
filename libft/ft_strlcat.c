/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:28:47 by ejang             #+#    #+#             */
/*   Updated: 2022/06/15 13:20:18 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = 0;
	while ((i + dest_len + 1 < dstsize) && (i < src_len))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (!(dstsize == 0 || dest_len > dstsize))
		dest[dest_len + i] = 0;
	if (dstsize < dest_len)
		return (src_len + dstsize);
	else
		return (src_len + dest_len);
}
