/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:43:46 by ejang             #+#    #+#             */
/*   Updated: 2021/04/11 17:17:24 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		check_valid(char *str)
{
	int i;
	int j;

	i = 0;
	if (len(str) == 1 || len(str) == 0)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-' || !(32 <= str[i] && str[i] <= 126))
			return (0);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			bs;
	long long	chg;

	bs = len(base);
	chg = (long long)nbr;
	if ((check_valid(base)) && (-2147483648 <= chg && chg <= 2147483647))
	{
		if ((chg < bs) && (chg >= 0))
			write(1, &base[chg], 1);
		else if (chg >= bs)
		{
			ft_putnbr_base(chg / bs, base);
			write(1, &base[chg % bs], 1);
		}
		else
		{
			chg = -chg;
			write(1, "-", 1);
			ft_putnbr_base(chg / bs, base);
			write(1, &base[chg % bs], 1);
		}
	}
}
