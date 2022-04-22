/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 06:03:48 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 19:30:16 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_deque *a, t_deque *b)
{
	int	chunk;

	if (a->size <= 3)
		sort_little(a);
	chunk = get_chunk(a);
	put_a_to_b(a, b, chunk);
	put_b_to_a(a, b);
}

int	get_chunk(t_deque *a)
{
	int	ret;
	ret = 0.000000053 * (a->size) * (a->size) +  0.03 * (a->size) + 14.5;
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
			instruct(a,b,"pb");
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
	if(find_loc(max, b) == 1)//상단
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

int	find_max(t_deque *b)
{
	int		ret;
	t_node	*temp;
	
	temp = b->rear;
	ret = temp->data;
	while(temp){
		if (temp->data > ret)
			ret = temp->data;
		temp = temp->llink;
	}
	return (ret);
}

int	find_loc(int max, t_deque *deque)
{
	int		ret;
	t_node	*temp;
	
	temp = deque->front;
	ret = 0;
	while(temp)
	{
		ret++;
		if (temp->data == max)
			break;
		temp = temp->rlink;
	}
	if (ret <= deque->size / 2)
		return (0);
	return (1);
}
