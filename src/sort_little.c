/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:46:11 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 19:30:11 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_little_three(t_deque *a)
{
	int	first;
	int	second;
	int	third;

	first = a->front->data;
	second = a->front->rlink->data;
	third = a->front->rlink->rlink->data;
	if (first < second && second < third && first < third)
	{
		instruct(a, NULL, "sa");
		instruct(a, NULL, "rra");
	}
	if(first < second && second > third && first < third)
		instruct(a, NULL, "rra");
	if (first > second && second < third && first < third)
		instruct(a, NULL, "ra");
	if (first < second && second > third && first > third)
	{
		instruct(a, NULL, "rra");
		instruct(a, NULL, "sa");
	}
	if (first > second && second < third && first > third)
		instruct(a, NULL, "sa");
}

void	sort_little(t_deque *a)
{
	if (a->size == 2)
		instruct(a, NULL, "sa");
	if (a->size == 3)
		sort_little_three(a);
	// if (a->size == 4)
	// ;
	// if (a->size == 5)
	// 	;
}