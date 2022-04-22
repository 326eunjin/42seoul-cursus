/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:11:04 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 22:33:43 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;

	if (argc < 2)
		exit(0);
	init_deque(&a);
	parse_argv(&a, argv);
	if (is_dup(&a) == -1)
	{
		free_deque(&a);
		print_error();
	}
	if (sort_check(&a) == 1)
	{
		free_deque(&a);
		return (0);
	}
	make_index(&a);
	init_deque(&b);
	push_swap(&a, &b);
	free_deque(&a);
	free_deque(&b);
}
