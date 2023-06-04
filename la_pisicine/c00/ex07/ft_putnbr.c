/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 04:48:20 by ejang             #+#    #+#             */
/*   Updated: 2021/04/06 11:46:56 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	prtostring(int nb)
{
	char c;

	c = nb + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int chg;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if ((nb < 10) && (nb >= 0))
		prtostring(nb);
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		prtostring(nb % 10);
	}
	else
	{
		chg = -nb;
		write(1, "-", 1);
		ft_putnbr(chg / 10);
		prtostring(chg % 10);
	}
}
