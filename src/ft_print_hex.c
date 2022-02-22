/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:39:52 by ejang             #+#    #+#             */
/*   Updated: 2022/02/22 23:17:24 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_getlen(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

static	char	*ft_print_hex_lower1(unsigned int nbr)
{
	int		i;
	int		temp;
	int		size;
	char	*tmp;

	i = 0;
	size = ft_getlen(nbr);
	tmp = malloc(sizeof(char) * (size + 1));
	if (tmp == NULL)
		return (0);
	tmp[size] = '\0';
	while (--size >= 0)
	{
		temp = nbr % 16 ;
		nbr = nbr / 16;
		if (temp > 9)
			tmp[size] = (temp + 87);
		else
			tmp[size] = (temp + '0');
	}
	return (tmp);
}

int	ft_print_hex_lower2(unsigned int nbr)
{	
	int		ret;
	int		i;
	char	*tmp;

	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	tmp = ft_print_hex_lower1(nbr);
	ret = ft_print_str(tmp);
	free(tmp);
	return (ret);
}

static	char	*ft_print_hex_upper1(unsigned int nbr)
{
	int		i;
	int		temp;
	int		size;
	char	*tmp;

	i = 0;
	size = ft_getlen(nbr);
	tmp = malloc(sizeof(char) * (size + 1));
	if (tmp == NULL)
		return (0);
	tmp[size] = '\0';
	while (--size >= 0)
	{
		temp = nbr % 16 ;
		nbr = nbr / 16;
		if (temp > 9)
			tmp[size] = (temp + 87 - 'a' + 'A');
		else
			tmp[size] = (temp + '0' - 'a' + 'A');
	}
	return (tmp);
}

int	ft_print_hex_upper2(unsigned int nbr)
{	
	int		ret;
	int		i;
	char	*tmp;

	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	tmp = ft_print_hex_upper1(nbr);
	ret = ft_print_str(tmp);
	free(tmp);
	return (ret);
}
