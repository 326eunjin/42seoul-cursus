/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_front.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:31:40 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 06:13:43 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_deque *deque)
{
	deque->rear = NULL;
	deque->front = NULL;
	deque->size = 0;
}

void	push_front(t_deque *deque, int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
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

int	pop_front(t_deque *deque)
{
	t_node	*del;
	int		ret;

	ret = 0;
	del = deque->front;
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

void	swap(t_deque *a, t_deque *b, int status)
{
	int	tmp1;
	int	tmp2;

	if (status == 0)
	{
		tmp1 = pop_back(a);
		tmp2 = pop_back(a);
		push_back(a, tmp1);
		push_back(a, tmp2);
	}
	else
	{
		tmp1 = pop_back(b);
		tmp2 = pop_back(b);
		push_back(b, tmp1);
		push_back(b, tmp2);
	}
}
