/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 04:12:01 by ejang             #+#    #+#             */
/*   Updated: 2022/06/01 19:44:27 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_all_finished(t_data *data)
{
	int ret;

	ret = FALSE;
	pthread_mutex_lock(&(data->end_lock));
	//printf("%d\n",data->people_cnt);
	if (data->people_cnt == data->number_of_philo)
	{
		data->end_flag = TRUE;
		pthread_mutex_unlock(&(data->end_lock));
		return (TRUE);
	}
	pthread_mutex_unlock(&(data->end_lock));
	return (FALSE);
}

int	is_dead_cond(t_philo *philo, t_data *data, int index)
{
	int ret;
	long long now;
	ret = FALSE;
	pthread_mutex_lock(&(philo[index].mutex));
	now = get_time();
	if ( now - philo[index].last_eat_time >= data->time_die)
	{
		pthread_mutex_lock(&(data->end_lock));
		printf("%lld %d %s\n", now - data->start_time, philo[index].id, DIED);
		data->end_flag = TRUE;
		pthread_mutex_unlock(&(philo[index].mutex));
		pthread_mutex_unlock(&(data->end_lock));
		return (TRUE);
	}
	pthread_mutex_unlock(&(philo[index].mutex));
	return (FALSE);
}

void *monitor(void *arg)
{
	t_philo *philo;
	t_data *data;
	int i;

	i = 0;
	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		//printf("monitor id : %d\n",philo->id);
		if ( i == data -> number_of_philo)
			i = 0;
		if (data->number_must_eat != 0 && is_all_finished(data) == TRUE)
			break;
		if (is_dead_cond(philo, data,i) == TRUE)
			break;
		i++;
		usleep(100);
	}
	return (NULL);
}