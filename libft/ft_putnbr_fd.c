/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 00:14:32 by ejang             #+#    #+#             */
/*   Updated: 2021/07/05 15:09:21 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	prtostring(int n, int fd)
{
	char	c;

	c = n + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if ((n < 10) && (n >= 0))
		prtostring(n, fd);
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		prtostring(n % 10, fd);
	}
	if (n >= -2147483647 && n < 0)
	{
		n = -1 * n;
		write(fd, "-", 1);
		if (n < 10 && n >= 0)
		{
			prtostring(n, fd);
			return ;
		}
		ft_putnbr_fd(n / 10, fd);
		prtostring(n % 10, fd);
	}
}
