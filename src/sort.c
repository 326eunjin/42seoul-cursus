/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:45:50 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 19:58:18 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_check(t_deque *deque)
{
	t_node	*ptr1;
	t_node	*ptr2;

	ptr1 = deque->front;
	while (ptr1 != NULL)
	{
		ptr2 = ptr1->rlink;
		while (ptr2 != NULL)
		{
			if (ptr1->data < ptr2->data)
				return (0);
			ptr2 = ptr2->rlink;
		}
		ptr1 = ptr1->rlink;
	}
	return (1);
}

void	make_index(t_deque	*deque)
{
	t_node	*ptr1;
	t_node	*ptr2;

	ptr1 = deque->front;
	while (ptr1 != NULL)
	{
		ptr2 = deque->front;
		while (ptr2 != NULL)
		{
			if (ptr1->data > ptr2->data)
				ptr1->tmp++;
			ptr2 = ptr2->rlink;
		}
		ptr1 = ptr1->rlink;
	}
	make_index_deque(deque);
}

void	make_index_deque(t_deque *deque)
{
	t_node	*temp;

	temp = deque->front;
	while (temp)
	{
		temp->data = temp->tmp;
		temp->tmp = 0;
		temp = temp->rlink;
	}
}
