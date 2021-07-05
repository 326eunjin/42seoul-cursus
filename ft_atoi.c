/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:59:14 by ejang             #+#    #+#             */
/*   Updated: 2021/07/05 15:08:52 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	res(int neg, long long nbr)
{
	if (((neg % 2) == 1) && (nbr == 2147483648))
		return (-2147483648);
	else if ((neg % 2) == 1)
		return ((int)(-1 * nbr));
	else
		return ((int)nbr);
}

int	ft_atoi(const char *str)
{
	int				neg;
	int				i;
	int				result;
	long long		nbr;

	i = 0;
	neg = 0;
	nbr = 0;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	result = res(neg, nbr);
	return (result);
}
