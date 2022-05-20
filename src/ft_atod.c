/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:41:53 by ejang             #+#    #+#             */
/*   Updated: 2022/05/20 02:49:45 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

long	ft_atol(char *str)
{
	long		ret;
	int			minus;
	int			i;

	ret = 0;
	minus = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i])
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	if (minus == -1)
		ret = ret * minus;
	return (ret);
}

double	ft_atod(char *str)
{
	double	ret;
	double	ret_2;
	int		i;
	char	*tmp;

	ret = 0;
	ret_2 = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	tmp = (char *)malloc(i + 1);
	ft_strlcpy(tmp, str, i + 1);
	ret = ft_atol(tmp);
	free(tmp);
	ret_2 = cal_ret2(i, str);
	if (str[0] == '-')
		ret = ret - ret_2;
	else
		ret = ret + ret_2;
	return (ret);
}

double	cal_ret2(int i, char *str)
{
	int		decimal_loc;
	int		decimal_len;
	int		j;
	double	ret_2;
	char	*tmp;

	ret_2 = 0;
	decimal_loc = i + 1;
	decimal_len = ft_strlen(str) - decimal_loc;
	tmp = (char *)malloc(decimal_len + 1);
	ft_strlcpy(tmp, str + decimal_loc, decimal_len + 1);
	j = 0;
	while (str[decimal_loc])
	{
		ret_2 = ret_2 + (str[decimal_loc] - 48) * pow(0.1, j + 1);
		j++;
		decimal_loc++;
	}
	free(tmp);
	return (ret_2);
}
