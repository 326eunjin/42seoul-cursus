/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:37:22 by jeyoon            #+#    #+#             */
/*   Updated: 2021/05/14 18:40:45 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*point_dst;
	unsigned char	*point_src;

	if (dst == src)
		return (dst);
	point_dst = (unsigned char*)dst;
	point_src = (unsigned char*)src;
	if (src < dst)
	{
		while (len--)
			*(point_dst + len) = *(point_src + len);
	}
	else
	{
		while (len--)
			*(point_dst++) = *(point_src++);
	}
	return (dst);
}
