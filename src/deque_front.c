/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_front.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:31:40 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 17:15:17 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
void	init_deque(t_deque *deque)
{
	deque->rear = NULL;
	deque->front = NULL;
	deque->size = 0;
}

void	push_bottom(t_deque *deque, int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->tmp = 0;
	new->data = data;
	if (deque->size == 0)
	{	
		deque->rear = new;
		deque->front = new;
		deque->size++;
		new->llink = NULL;
		new->rlink = NULL;
	}
	else
	{
		deque->front->llink = new;
		new->rlink = deque->front;
		new->llink = NULL;
		deque->front = new;
		deque->size++;
	}
}

int	pop_bottom(t_deque *deque)
{
	t_node	*del;
	int		ret;

	ret = 0;
	del = deque->front;
	del->tmp = 0;
	if (deque->size == 0)
		print_pop_push_error(deque);
	ret = del->data;
	if (deque->front->rlink == NULL)
	{
		deque->front = NULL;
		deque->rear = NULL;
	}
	else
	{
		deque->front = deque->front->rlink;
		deque->front->llink = NULL;
	}
	free(del);
	deque->size--;
	return (ret);
}

void	swap(t_deque *deque)
{
	int	tmp1;
	int	tmp2;
	tmp1 = pop_top(deque);
	tmp2 = pop_top(deque);
	push_top(deque, tmp1);
	push_top(deque, tmp2);
}

void	push(t_deque *deque1, t_deque *deque2)
{
	int	tmp;

	tmp = pop_top(deque2);
	push_top(deque1, tmp);
}
