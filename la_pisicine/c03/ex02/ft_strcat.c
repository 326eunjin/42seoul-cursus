/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:38:48 by ejang             #+#    #+#             */
/*   Updated: 2021/04/08 17:16:32 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	unsigned int i;
	unsigned int cnt;

	cnt = 0;
	i = 0;
	while (dest[cnt] != '\0')
	{
		cnt++;
	}
	while (src[i] != '\0')
	{
		dest[cnt + i] = src[i];
		i++;
	}
	dest[cnt + i] = '\0';
	return (dest);
}
