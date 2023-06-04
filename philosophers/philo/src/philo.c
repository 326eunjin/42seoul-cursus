/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:11:14 by ejang             #+#    #+#             */
/*   Updated: 2022/06/03 15:34:57 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	while (is_dead(philo->data) != -1)
	{
		if (philo_eat(philo) == -1)
			break ;
		if (philo_sleep(philo) == -1)
			break ;
		if (philo->data->number_must_eat != -1 && is_finished(philo) == TRUE)
		{
			pthread_mutex_lock(&(philo->mutex));
			philo->eat_cnt++;
			pthread_mutex_unlock(&(philo->mutex));
		}
		if (philo_think(philo) == -1)
			break ;
		usleep(100);
	}
	return (NULL);
}

int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->left]);
	if (is_dead(philo->data) == 1)
		print_philo(philo, HAS_FORK);
	if (philo->data->number_of_philo == 1)
	{
		msleep(philo->data->time_die);
		return (-1);
	}
	pthread_mutex_lock(&philo->data->fork[philo->right]);
	if (is_dead(philo->data) == 1)
		print_philo(philo, HAS_FORK);
	pthread_mutex_lock(&philo->mutex);
	philo->eat_cnt++;
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->mutex);
	if (is_dead(philo->data) == 1)
		print_philo(philo, IS_EATING);
	msleep(philo->data->time_eat);
	pthread_mutex_unlock(&philo->data->fork[philo->left]);
	pthread_mutex_unlock(&philo->data->fork[philo->right]);
	if (is_dead(philo->data) == -1)
		return (-1);
	return (TRUE);
}

int	philo_sleep(t_philo *philo)
{
	if (is_dead(philo->data) == 1)
		print_philo(philo, IS_SLEEPING);
	msleep(philo->data->time_sleep);
	if (is_dead(philo->data) == -1)
		return (-1);
	return (TRUE);
}

int	philo_think(t_philo *philo)
{
	if (is_dead(philo->data) == 1)
		print_philo(philo, IS_THINKING);
	return (TRUE);
}

int	is_finished(t_philo *philo)
{
	pthread_mutex_lock(&(philo->mutex));
	if (philo->eat_cnt == philo->data->number_must_eat)
	{	
		philo->data->people_cnt++;
		pthread_mutex_unlock(&(philo->mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&(philo->mutex));
	return (FALSE);
}
