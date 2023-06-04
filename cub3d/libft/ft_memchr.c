/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:41:19 by ejang             #+#    #+#             */
/*   Updated: 2022/06/15 13:19:04 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*tmp;
	size_t		i;

	i = 0;
	tmp = (const char *)s;
	while (i < n)
	{
		if ((unsigned char)tmp[i] == (unsigned char)c)
			return ((void *)(tmp + i));
		i++;
	}
	return (NULL);
}
