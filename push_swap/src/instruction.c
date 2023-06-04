/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 06:50:52 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 19:54:32 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_deque *a, t_deque *b)
{
	swap(a);
	swap(b);
}

void	rr(t_deque *a, t_deque *b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_deque *a, t_deque *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	instruct(t_deque *a, t_deque *b, char *inst)
{
	if (ft_strcmp("sa", inst) == 0)
		swap(a);
	else if (ft_strcmp("sb", inst) == 0)
		swap(b);
	else if (ft_strcmp("ss", inst) == 0)
		ss(a, b);
	else if (ft_strcmp("pa", inst) == 0)
		push(a, b);
	else if (ft_strcmp("pb", inst) == 0)
		push(b, a);
	else if (ft_strcmp("ra", inst) == 0)
		rotate(a);
	else if (ft_strcmp("rb", inst) == 0)
		rotate(b);
	else if (ft_strcmp("rr", inst) == 0)
		rr(a, b);
	else if (ft_strcmp("rra", inst) == 0)
		reverse_rotate(a);
	else if (ft_strcmp("rrb", inst) == 0)
		reverse_rotate(b);
	else if (ft_strcmp("rrr", inst) == 0)
		rrr(a, b);
	ft_putstr_fd(inst, 1);
	ft_putstr_fd("\n", 1);
}
