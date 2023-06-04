/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 06:03:48 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 22:34:58 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_deque *a, t_deque *b)
{
	int	chunk;

	if (a->size <= 5 && a->size != 4)
	{
		sort_little(a, b);
		free_deque(a);
		free_deque(b);
		exit(0);
	}
	chunk = get_chunk(a);
	put_a_to_b(a, b, chunk);
	put_b_to_a(a, b);
}

int	get_chunk(t_deque *a)
{
	int	ret;

	ret = 0.000000053 * (a->size) * (a->size) + 0.03 * (a->size) + 14.5;
	return (ret);
}

void	put_a_to_b(t_deque *a, t_deque *b, int chunk)
{
	int	num;
	int	top;

	num = 0;
	while (a->size != 0)
	{
		top = get_top_element(a);
		if (top <= num)
		{
			instruct(a, b, "pb");
			num++;
		}
		else if (num + chunk < top)
			instruct(a, b, "ra");
		else
		{
			instruct(a, b, "pb");
			instruct(a, b, "rb");
			num++;
		}
	}
}

void	put_b_to_a(t_deque *a, t_deque *b)
{
	while (b->size != 0)
	{
		move_big_top(b);
		instruct(a, b, "pa");
	}
}

void	move_big_top(t_deque *b)
{
	int	max;

	max = find_max(b);
	if (find_loc(max, b) == 1)
	{
		while (get_top_element(b) != max)
		{
			instruct(NULL, b, "rb");
			max = find_max(b);
		}
	}
	else
	{
		while (get_top_element(b) != max)
		{
			instruct(NULL, b, "rrb");
			max = find_max(b);
		}
	}
}
