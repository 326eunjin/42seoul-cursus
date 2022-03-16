/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:17:08 by ejang             #+#    #+#             */
/*   Updated: 2022/02/23 02:38:49 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	print_format(char ch, va_list *ap)
{
	int	len;

	len = 0;
	if (ch == 'c')
		len = ft_print_char(va_arg(ap, int));
	if (ch == 's')
		len = ft_print_str(va_arg(ap, char *));
	else if (ch == 'p')
		len = ft_print_pointer(va_arg(ap, unsigned long long));
	else if (ch == 'd' || ch == 'i')
		len = ft_print_nbr(va_arg(ap, int));
	else if (ch == 'u')
		len = ft_print_unnbr(va_arg(ap, unsigned int));
	else if (ch == 'x')
		len = ft_print_hex_lower2(va_arg(ap, unsigned int));
	else if (ch == 'X')
		len = ft_print_hex_upper2(va_arg(ap, unsigned int));
	else if (ch == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

static char	is_valid_format(char ch)
{
	if (ch == 'c' || ch == 's' || ch == 'p'
		|| ch == 'd' || ch == 'i' || ch == 'u'
		|| ch == 'x' || ch == 'X' || ch == '%')
		return (1);
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (!is_valid_format(str[i + 1]))
				return (-1);
			count += print_format(str[i + 1], ap);
			i += 2;
		}
		else
		{
			count += ft_print_char(str[i]);
			i++;
		}
	}
	va_end(ap);
	return (count);
}
