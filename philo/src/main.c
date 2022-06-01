/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:39:39 by ejang             #+#    #+#             */
/*   Updated: 2022/06/01 17:45:40 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_data data;//argv로 들어온 값 처리하는 구조체
	t_philo *philo;//철학자 배열

	parse_init(argc, argv, &data);//data 구조체 초기화
	philo = (t_philo *)malloc(sizeof(t_philo) * data.number_of_philo);
	//구조체 배열 
	if (!philo)//배열 할당 실패시 에러 처리
		return (FALSE);
	if (philo_init(&data,philo) == FALSE)//철학자 초기화
		return (0);//초기화 실패하면 프로그램 종료
	if (make_thread(&data, philo) == FALSE)//철학자 스레드 생성
	{
		free(philo);
		return (0);
	}
	free_philo_end(philo);
	return (0);
}
