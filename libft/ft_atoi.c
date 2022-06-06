/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:24:56 by jeyoon            #+#    #+#             */
/*   Updated: 2021/05/13 14:45:06 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

static unsigned int	atonbr(const char *str, int idx)
{
	unsigned int	nbr;

	nbr = 0;
	while (str[idx] != '\0')
	{
		if (ft_isdigit(str[idx]))
			nbr = nbr * 10 + (str[idx] - '0');
		else
			break ;
		idx++;
	}
	return (nbr);
}

int					ft_atoi(const char *str)
{
	unsigned int	nbr;
	int				sign;
	int				i;

	i = 0;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	nbr = atonbr(str, i);
	if (sign == -1 && nbr > 2147483648)
		return (0);
	if (sign == 1 && nbr > 2147483647)
		return (-1);
	return ((int)(nbr * sign));
}
