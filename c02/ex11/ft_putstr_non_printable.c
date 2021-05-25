/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:27:59 by ejang             #+#    #+#             */
/*   Updated: 2021/04/11 14:48:39 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_printable(char ch)
{
	if ((ch >= 32) && (ch <= 126))
		return (1);
	return (0);
}

char	hex(unsigned char ch)
{
	if (ch > 9)
		ch += 87;
	else
		ch += 48;
	return (ch);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char first;
	unsigned char second;

	while (*str != '\0')
	{
		if (is_printable(*str) == 0)
		{
			first = hex((unsigned char)*str / 16);
			second = hex((unsigned char)*str % 16);
			write(1, "\\", 1);
			write(1, &first, 1);
			write(1, &second, 1);
		}
		else
			write(1, str, 1);
		str++;
	}
}
