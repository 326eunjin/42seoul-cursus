/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:21:14 by ejang             #+#    #+#             */
/*   Updated: 2022/06/01 06:43:26 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	msleep(int time)
{
	long long	temp;

	temp = get_time();
	while (get_time() < temp + time)
		usleep(500);
}

int	is_dead(t_data *data)
{
	int ret;

	ret = 1;
	pthread_mutex_lock(&data->end_lock);
	if (data->end_flag == TRUE)
		ret = -1;
	pthread_mutex_unlock(&data->end_lock);
	return (ret);
}

void print_philo(t_philo *philo, char* msg)
{
	pthread_mutex_lock(&philo->data->print_lock);
	printf("%lld %d %s",get_time() - philo->data->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_lock);
}