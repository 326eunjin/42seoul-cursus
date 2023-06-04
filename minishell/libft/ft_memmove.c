/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:08:42 by ejang             #+#    #+#             */
/*   Updated: 2022/06/15 13:19:17 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	if (!dst && !src)
		return (NULL);
	dest = (char *)dst;
	source = (const char *)src;
	if (dest <= source)
	{
		while (len--)
		{
			*dest++ = *source++;
		}
	}
	else
	{
		dest += len;
		source += len;
		while (len--)
			*(--dest) = *(--source);
	}
	return (dst);
}
