/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:07:50 by ejang             #+#    #+#             */
/*   Updated: 2022/06/01 21:38:27 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define HAS_FORK "\033[0;32mhas taken a fork\033[0m"
# define IS_EATING "\033[0;36mis eating\033[0m"
# define IS_SLEEPING "\033[0;34mis sleeping\033[0m"
# define IS_THINKING "\033[0;33mis thinking\033[0m"
# define DIED "\033[0;31mdied\033[0m"

typedef struct s_data
{
	int				number_of_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				number_must_eat;
	int				end_flag;
	long long		start_time;
	int				people_cnt;
	pthread_mutex_t	*fork;
	pthread_mutex_t	end_lock;
	pthread_mutex_t	print_lock;
	pthread_t		monitor;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				left;
	int				right;
	int				eat_cnt;
	long long		last_eat_time;
	pthread_mutex_t	mutex;
	t_data			*data;
}	t_philo;

int			init_error(void);
void		free_philo(t_philo *philo, int index);
void		free_philo_end(t_philo *philo);

int			parse_init(int argc, char **argv, t_data *data);
int			philo_init(t_data *data, t_philo *philo);
int			mutex_init(t_philo *philo);
int			make_thread(t_data *data, t_philo *philo);

int			is_all_finished(t_data *data);
int			is_dead_cond(t_philo *philo, t_data *data, int index);
void		*monitor(void *arg);

void		*routine(void *arg);
int			philo_eat(t_philo *philo);
int			philo_sleep(t_philo *philo);
int			philo_think(t_philo *philo);
int			is_finished(t_philo *philo);

int			ft_isdigit(char c);
int			res(long long nbr);
int			ft_atoi(const char *str);
int			is_correct_input(const char *str);
long long	get_time(void);

void		msleep(int time);
int			is_dead(t_data *data);
void		print_philo(t_philo *philo, char *msg);

#endif