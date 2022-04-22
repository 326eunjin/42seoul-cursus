/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:46:11 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 22:13:26 by ejang            ###   ########.fr       */
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
	if (first < second && second > third && first < third)
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

void	sort_little(t_deque *a, t_deque *b)
{
	if (a->size == 2)
		instruct(a, NULL, "sa");
	if (a->size == 3)
		sort_little_three(a);
	else
		sort_little_five(a, b);
}

void	sort_little_five(t_deque *a, t_deque *b)
{
	int	mid;
	int	pb;

	pb = 0;
	mid = 2;
	while (1)
	{
		if (get_top_element(a) < mid)
		{
			instruct(a, b, "pb");
			pb++;
		}
		else
			instruct(a, b, "ra");
		if (pb == 2)
			break ;
	}
	sort_little_three(a);
	if (b->front->data > b->front->rlink->data)
		instruct(NULL, b, "sb");
	instruct(a, b, "pa");
	instruct(a, b, "pa");
}
