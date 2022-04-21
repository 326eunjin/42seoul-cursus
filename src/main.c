/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:11:04 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 06:16:57 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// #include <stdio.h>
// void printDQ(t_deque *DQ) // 기본 출력 문구 및 출력 위치 선정

// {

// t_node *temp = DQ->front;

// printf("\n DeQue : [");

// while(temp) {

// printf("%3d\n", temp->data);

// temp = temp->rlink;

// }

// printf(" ]");

// }

int	main(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;

	if (argc < 2)
		print_error();
	init_stack(&a);
	parse_argv(&a, argv);
	if (is_dup(&a) == -1)
	{
		free_deque(&a);
		print_error();
	}
	printf("no dup\n");
	if (sort_check(&a) == 1)//정렬된 상태인지 확인 정렬되어있으면 1
	{
		free_deque(&a);
		return (0);
	}
	//sorting problem and index not changed;
	make_index(&a);
	init_stack(&b);
	if (a.size < 5)
		sort_little(&a);//if size is 3 or 5 hand coding
	push_swap(&a, &b);
	printDQ(&a);
	free_deque(&a);
	free_deque(&b);
}
