/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:36:27 by jeyoon            #+#    #+#             */
/*   Updated: 2021/05/18 15:20:16 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*point_dst;
	unsigned char	*point_src;
	size_t			i;

	if (dst == src)
		return (dst);
	point_dst = (unsigned char*)dst;
	point_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		*(point_dst + i) = *(point_src + i);
		i++;
	}
	return (dst);
}
