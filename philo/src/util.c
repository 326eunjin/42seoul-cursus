/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:13:26 by ejang             #+#    #+#             */
/*   Updated: 2022/06/01 21:37:57 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (c);
	else
		return (0);
}

int	res(long long nbr)
{
	if (nbr >= 2147483648)
		return (-1);
	else
		return ((int)nbr);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				result;
	long long		nbr;

	i = 0;
	nbr = 0;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	result = res(nbr);
	return (result);
}

int	is_correct_input(const char *str)
{
	if (ft_atoi(str) > 0)
		return (1);
	else
		return (-1);
}

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}
