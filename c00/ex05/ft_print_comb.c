/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:56:20 by ejang             #+#    #+#             */
/*   Updated: 2021/04/04 00:49:09 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char i, char j, char k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
}

void	ft_print_comb(void)
{
	char i;
	char j;
	char k;

	i = 47;
	j = 47;
	k = 47;
	while (++i <= '9')
	{
		while (++j <= '9')
		{
			while (++k <= '9')
			{
				if ((j > i) && (k > j))
				{
					print(i, j, k);
					if (!((i == '7') && (j == '8') && (k == '9')))
						write(1, ", ", 2);
				}
			}
			k = 0;
		}
		j = 0;
	}
}
