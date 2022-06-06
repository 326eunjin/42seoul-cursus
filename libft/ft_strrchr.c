/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:32:22 by ejang             #+#    #+#             */
/*   Updated: 2021/07/03 23:10:17 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str);
	if (c == '\0')
		return ((char *)(str + len));
	while (len--)
	{
		if (str[len] == (char)c)
			return ((char *)(str + len));
	}
	return (NULL);
}
