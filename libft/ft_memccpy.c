/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:32:49 by jeyoon            #+#    #+#             */
/*   Updated: 2021/05/12 11:34:25 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*point_dst;
	unsigned char	*point_src;
	size_t			i;

	i = 0;
	point_dst = (unsigned char*)dst;
	point_src = (unsigned char*)src;
	while (i < n)
	{
		*point_dst = *point_src;
		if (*point_src == (unsigned char)c)
			break ;
		i++;
		point_dst++;
		point_src++;
	}
	if (i != n)
		return (++point_dst);
	else
		return (NULL);
}
