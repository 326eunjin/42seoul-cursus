/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:01:10 by heehkim           #+#    #+#             */
/*   Updated: 2021/04/03 22:28:12 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

extern	char g_condition[16];
extern	char g_arr[4][4];
extern	int g_arr_num[8];
extern	bool g_is_solve;

int		is_promising(int row, int col, int num);
bool	is_valid(int i);
void	solve_arr(void);

void	print_arr(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, g_arr[i] + j, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	set_arr(int row, int col, char num)
{
	g_arr[row][col] = num;
	if (num == 0)
	{
		g_arr_num[row + 4] -= 1;
		g_arr_num[col] -= 1;
	}
	else
	{
		g_arr_num[row + 4] += 1;
		g_arr_num[col] += 1;
	}
}

void	sub_solve_arr(int row, int col, char num, int arr_num_cnt)
{
	while (num <= '4')
	{
		if (is_promising(row, col, num))
		{
			arr_num_cnt = 0;
			set_arr(row, col, num);
			while (arr_num_cnt++ < 8)
			{
				if (g_arr_num[arr_num_cnt] == 4)
				{
					if (!is_valid(arr_num_cnt))
					{
						set_arr(row, col, 0);
						arr_num_cnt = -1;
						break ;
					}
				}
			}
			if (arr_num_cnt == -1)
				break ;
			solve_arr();
			set_arr(row, col, 0);
		}
		num++;
	}
}

void	find_blank(int *row, int *col)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (g_arr[i][j] == 0)
			{
				*row = i;
				*col = j;
				break ;
			}
			j++;
		}
		if (*row != -1)
			break ;
		i++;
	}
}

void	solve_arr(void)
{
	int		row;
	int		col;
	char	num;

	row = -1;
	col = -1;
	find_blank(&row, &col);
	if (row == -1)
	{
		print_arr();
		g_is_solve = true;
	}
	num = '1';
	sub_solve_arr(row, col, num, 0);
}
