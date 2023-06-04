/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:39:39 by ejang             #+#    #+#             */
/*   Updated: 2022/06/01 21:45:23 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (parse_init(argc, argv, &data) == FALSE)
		return (0);
	philo = (t_philo *)malloc(sizeof(t_philo) * data.number_of_philo);
	if (!philo)
		return (FALSE);
	if (philo_init(&data, philo) == FALSE)
		return (0);
	if (make_thread(&data, philo) == FALSE)
	{
		free(philo);
		return (0);
	}
	free_philo_end(philo);
	return (0);
}
