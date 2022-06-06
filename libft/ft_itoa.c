/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:20:33 by jeyoon            #+#    #+#             */
/*   Updated: 2021/05/18 14:38:12 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	ft_abs(int n)
{
	if (n > 0)
		return ((unsigned int)n);
	else
		return ((unsigned int)(n * -1));
}

static int				ft_get_len(unsigned int nbr, int sign)
{
	int					len;

	len = 0;
	if (sign == -1)
		len = 1;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char					*ft_itoa(int n)
{
	int					sign;
	unsigned int		nbr;
	int					len;
	char				*temp;

	sign = 1;
	if (n < 0)
		sign = -1;
	nbr = ft_abs(n);
	len = ft_get_len(nbr, sign);
	if (!(temp = (char *)malloc(len + 1)))
		return (NULL);
	temp[len--] = '\0';
	while (len > 0)
	{
		temp[len] = '0' + (nbr % 10);
		nbr /= 10;
		len--;
	}
	if (sign == -1)
		temp[0] = '-';
	else
		temp[0] = '0' + (nbr % 10);
	return (temp);
}
