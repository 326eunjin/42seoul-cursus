/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:06:29 by ejang             #+#    #+#             */
/*   Updated: 2022/03/31 21:20:06 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*ptr;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = (char *)malloc(len1 + len2 + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len1 + 1);
	ft_strlcpy(ptr + len1, s2, len2 + 1);
	return (ptr);
}
