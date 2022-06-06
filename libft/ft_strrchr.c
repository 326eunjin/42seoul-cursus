/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:46:18 by jeyoon            #+#    #+#             */
/*   Updated: 2021/05/12 15:24:52 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*temp;

	temp = (char*)s;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (*(temp + i) == (char)c)
			return (temp + i);
		i--;
	}
	if (*(temp + i) == (char)c)
		return (temp);
	return (NULL);
}
