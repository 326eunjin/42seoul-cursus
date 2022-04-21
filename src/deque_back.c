/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:36:02 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 06:12:07 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_back(t_deque *deque, int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	if (deque->size == 0)
	{
		deque->front = new;
		deque->rear = new;
		new->rlink = NULL;
		new->llink = NULL;
		deque->size++;
	}
	else
	{
		deque->rear->rlink = new;
		new->rlink = NULL;
		new->llink = deque->rear;
		deque->rear = new;
		deque->size++;
	}
}

int	pop_back(t_deque *deque)
{
	t_node	*del;
	int		ret;

	ret = 0;
	del = deque -> rear;
	if (deque->size == 0)
		print_pop_push_error(deque);
	ret = del->data;
	if (deque->rear->llink == NULL)
	{
		deque->front = NULL;
		deque->rear = NULL;
	}
	else
	{
		deque->rear = deque->rear->llink;
		deque->rear->rlink = NULL;
	}
	free(del);
	deque->size--;
	return (ret);
}
