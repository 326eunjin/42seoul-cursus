/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:48:13 by ejang             #+#    #+#             */
/*   Updated: 2022/06/01 20:26:51 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_error(void)
{
	printf("INIT ERROR\n");
	return (FALSE);
}

void free_philo(t_philo *philo, int index)
{
	int i;
	i = 0;
	while(i< index)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

void free_philo_end(t_philo* philo)
{
	int i;
	
	i = 0;
	while (i < philo->data->number_of_philo)
	{
		pthread_mutex_destroy(&(philo->data->fork[i]));
		pthread_mutex_destroy(&philo[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&(philo->data->end_lock));
	pthread_mutex_destroy(&(philo->data->print_lock));
	free(philo->data->fork);
	free(philo);
}
