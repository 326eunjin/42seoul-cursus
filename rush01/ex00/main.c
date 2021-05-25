/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:40:37 by heehkim           #+#    #+#             */
/*   Updated: 2021/04/03 22:00:03 by chhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

int		is_valid_input(char *cond);
void	solve_arr(void);
char	g_condition[16] = {0};
char	g_arr[4][4] = {0};
int		g_arr_num[8] = {0};
bool	g_is_solve = false;

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (is_valid_input(argv[1]))
			solve_arr();
	}
	if (!g_is_solve)
		write(1, "Error\n", 6);
	return (0);
}
