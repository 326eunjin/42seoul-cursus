/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:08:44 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 06:15:45 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	print_pop_push_error(t_deque *deque)
{
	free_deque(deque);
	write(1, "cannot push or pop\n", 19);
	exit(1);
}

void	free_deque(t_deque *deque)
{
	t_node	*tmp;

	deque->rear = NULL;
	while (deque->front != NULL)
	{
		tmp = deque->front;
		deque->front = deque->front->rlink;
		free(tmp);
	}
	deque->size = 0;
}

void	free_split(char **args)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (args[size])
		size++;
	while (i < size)
		free(args[i++]);
	free(args);
}
