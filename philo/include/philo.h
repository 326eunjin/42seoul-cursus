/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:07:50 by ejang             #+#    #+#             */
/*   Updated: 2022/06/01 06:47:07 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
# define HAS_FORK "\033[0;32mhas taken a fork\033[0m"
# define IS_EATING "\033[0;36mis eating\033[0m"
# define IS_SLEEPING "\033[0;34mis sleeping\033[0m"
# define IS_THINKING "\033[0;33mis thinking\033[0m"
# define DIED "\033[0;31mdied\033[0m"
typedef struct s_data
{
	int number_of_philo;//첫 번째 인자, 철학자 명수
	int time_die;
	//밀리초 단위로, 철학자가 마지막으로 밥을 먹은 지 'time_to_die' 시간만큼이 지나거나, 프로그램 시작 후 'time_to_die' 시간만큼이 지나면 해당 철학자는 사망합니다
	int time_eat;//먹는 시간
	int time_sleep;//자는 시간
	int number_must_eat;//모든 철학자가 이만큼 밥 먹으면 시뮬레이션 종료
	int	end_flag;//end_flag 값에 따라서 프로그램 종료 결정, 한 명이라도 죽으면 이제 프로그램이 종료되어야 함.
	long long start_time;//프로그램 시작 시간
	int	people_cnt;
	pthread_mutex_t *fork;//각각의 포크는 이제 뮤텍스가 될 것이다! 이게 배열인 이유는 철학자 명수에 따라서 갯수가 다르기 때문,,
	// 뮤텍스 1. data 접근할 때 쓸 뮤텍스(end flag)
	pthread_mutex_t end_lock;
	pthread_mutex_t print_lock;
	// 뮤텍스 2. 프린트 할 때 쓸 뮤텍스 안쓰면 섞임
	pthread_t monitor;//죽었는지 안 죽었는지 확인하는 스레드 
}	t_data;

typedef struct s_philo
{
	pthread_t thread;//철학자마다 고유의 스레드를 가질 것
	int id;//철학자 이름 출력시 필요함
	int left;//왼쪽 포크
	int right;//오른쪽 포크
	int eat_cnt;//몇번 먹었는지?
	long long	last_eat_time;//마지막으로 먹은 시간 이를 기준으로 사망여부 파악
	pthread_mutex_t mutex;
	t_data	*data;//함수 넘겨줄 때 필요함,,!
}	t_philo;

int	init_error(void);
void	free_philo(t_philo *philo, int index);
void	free_philo_end(t_philo* philo);

int parse_init(int argc, char **argv, t_data *data);
int	philo_init(t_data *data, t_philo *philo);
int mutex_init(t_philo *philo);
int	make_thread(t_data *data, t_philo *philo);

int	is_all_finished(t_data *data);
int	is_dead_cond(t_philo *philo, t_data *data, int index);
void *monitor(void *arg);

void *routine(void *arg);
int philo_eat(t_philo *philo);
int philo_sleep(t_philo *philo);
int	philo_think(t_philo *philo);
int	is_finished(t_philo *philo);

int	ft_isdigit(char c);
int	res(int neg, long long nbr);
int	ft_atoi(const char *str);
int	is_correct_input(const char * str);
long long get_time(void);

void	msleep(int time);
int	is_dead(t_data *data);
void print_philo(t_philo *philo, char* msg);

#endif