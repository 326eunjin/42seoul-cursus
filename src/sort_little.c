/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:46:11 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 15:43:56 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_little_three(t_deque *a)
{
	int first = a->front->data;
	int second = a->front->rlink->data;
	int third = a->front->rlink->rlink->data;

	//bottom 3 2 1 top is sorted
	// bottom 1 2 3 top  
	if (first < second && second < third && first < third)
	{
		instruct(a, NULL, "rra");
		instruct(a, NULL, "rra");
	}
	// 1 3 2
	if(first < second && second > third && first< second)
		instruct(a, NULL, "rra");
	//2 1 3 pop top push bottom
	if (first > second && second < third && first < third)
		instruct(a, NULL, "ra");
	// bottom 2 3 1 top   
	if (first < second && second > third && first > third)
	{
		instruct(a, NULL, "rra");
		instruct(a, NULL, "sa");
	}
	// 3 1 2 
	if (first > second && second < third && first > third)
		instruct(a, NULL, "sa");
}

void	sort_little_five(t_deque *a, t_deque *b)
{

}

void	sort_little(t_deque *a, t_deque *b)
{//2
	if (a->size == 2)
	{
		if(a->front->data < a->front->rlink->data)//bottom 2 3
			instruct(a, NULL, "sa");
	}
//3
	if (a->size == 3)
		sort_little_three(a);
//4
	if (a->size == 4)
	;
//5
	if (a->size == 5)
		;
}