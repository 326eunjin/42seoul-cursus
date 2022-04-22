/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:02:47 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 22:14:32 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_max(t_deque *b)
{
	int		ret;
	t_node	*temp;

	temp = b->rear;
	ret = temp->data;
	while (temp)
	{
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
	while (temp)
	{
		ret++;
		if (temp->data == max)
			break ;
		temp = temp->rlink;
	}
	if (ret <= deque->size / 2)
		return (0);
	return (1);
}
