/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:35:21 by jeyoon            #+#    #+#             */
/*   Updated: 2021/05/12 11:36:20 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*point_s1;
	unsigned char	*point_s2;
	size_t			i;

	i = 0;
	point_s1 = (unsigned char*)s1;
	point_s2 = (unsigned char*)s2;
	while (i++ < n)
	{
		if (*point_s1 != *point_s2)
			return (*point_s1 - *point_s2);
		point_s1++;
		point_s2++;
	}
	return (0);
}
