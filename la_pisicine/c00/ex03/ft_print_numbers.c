/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:45:23 by ejang             #+#    #+#             */
/*   Updated: 2021/04/01 11:48:08 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print_numbers(void)
{
	char c;

	c = '0';
	while (c <= '9')
	{
		write(1, &c, 1);
		c++;
	}
}