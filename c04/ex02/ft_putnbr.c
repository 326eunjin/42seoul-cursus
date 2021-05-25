/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:45:32 by ejang             #+#    #+#             */
/*   Updated: 2021/04/12 01:14:23 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	prtostring(int nb)
{
	char c;

	c = nb + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if ((nb < 10) && (nb >= 0))
		prtostring(nb);
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		prtostring(nb % 10);
	}
	if (nb >= -2147483647 && nb < 0)
	{
		nb = -1 * nb;
		write(1, "-", 1);
		if (nb < 10 && nb >= 0)
		{
			prtostring(nb);
			return ;
		}
		ft_putnbr(nb / 10);
		prtostring(nb % 10);
	}
}
