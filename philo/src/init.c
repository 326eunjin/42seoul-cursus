/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:04:11 by ejang             #+#    #+#             */
/*   Updated: 2022/06/01 16:40:15 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int parse_init(int argc, char **argv, t_data *data)//data 초기화
{
	int i = 1;
	if (argc == 5 || argc == 6)
	{
		while(i<argc)
		{
			if(is_correct_input(argv[i]) == -1)
				init_error();
			i++;
		}
		data->number_of_philo = ft_atoi(argv[1]);
		data->time_die = ft_atoi(argv[2]);
		data->time_eat = ft_atoi(argv[3]);
		data->time_sleep = ft_atoi(argv[4]);
		data->end_flag = FALSE;
		data->number_must_eat = -1;
		data->people_cnt = -1;
		if (argc == 6)
		{
			data->number_must_eat = ft_atoi(argv[5]);
			data->people_cnt = 0;
		}
	}
	else
		init_error();
	return (TRUE);
}

int	philo_init(t_data *data, t_philo *philo)//철학자 초기화
{
	//철학자 수만큼 동적할당
	int i;
	philo = (t_philo *)malloc(sizeof(t_philo) * data->number_of_philo);
	//구조체 배열 
	if (!philo)//배열 할당 실패시 에러 처리
		return (FALSE);
	i = 0;
	while (i < data->number_of_philo)
	{
		philo[i].id = i + 1;//id는 1부터 시작
		philo[i].left = i;//왼쪽 포크
		philo[i].right = (i + 1) % data->number_of_philo;
		philo[i].eat_cnt = 0;//몇번 먹었는지
		philo[i].data = data;
		philo[i].last_eat_time = get_time();
		i++;
	}
	printf("%d\n",philo[0].id);
	mutex_init(philo);
	printf("%d\n",philo[0].id);
	return (TRUE);
}

int mutex_init(t_philo *philo)//뮤텍스 초기화
{
	int i;

	philo->data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo->data->number_of_philo);
	if (!philo->data->fork)
		return (FALSE);
	i = 0;
	while (i < philo->data->number_of_philo)
	{
		if (pthread_mutex_init(&(philo->data->fork[i]),NULL)!= 0)
			return (FALSE);
		i++;
	}
	if (pthread_mutex_init(&(philo->data->print_lock),NULL)!=0)
		return (FALSE);
	if (pthread_mutex_init(&(philo->data->end_lock),NULL)!=0)
		return (FALSE);
	if (pthread_mutex_init(&(philo->mutex),NULL)!=0)
		return (FALSE);
	return (TRUE);
}

int	make_thread(t_data *data, t_philo *philo)
{
	int i;
	long long start_time;

	start_time = get_time();
	i = 0;
	if (pthread_create(&data->monitor, NULL, monitor, (void *)philo) != 0)
		return (FALSE);
	data->start_time = start_time;
	for (i = 0;i<data->number_of_philo;i++)
		printf("id %d %d\n",i,philo[i].id);
	while (i < data->number_of_philo)
	{
		philo[i].last_eat_time = start_time;
		if (pthread_create(&philo[i].thread, NULL, routine, (void *)&philo[i]) != 0)
		{
			data->end_flag = TRUE;
			free_philo(philo, i);
			return (FALSE);
		}
		i++;
	}
	pthread_join(data->monitor, NULL);
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (TRUE);
}