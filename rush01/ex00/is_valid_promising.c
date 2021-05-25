/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_promising.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:00:05 by heehkim           #+#    #+#             */
/*   Updated: 2021/04/03 21:53:11 by heehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

extern char	g_condition[16];
extern char	g_arr[4][4];
extern int	g_arr_num[8];
extern bool	g_is_solve;

int		is_promising(int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_arr[row][i] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (g_arr[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

bool	check_vertical(int i, int j, char num)
{
	int tmp;

	tmp = g_arr[j][i];
	while (j++ < 3)
	{
		if (tmp < g_arr[j][i])
		{
			tmp = g_arr[j][i];
			num++;
		}
	}
	if ((num == g_condition[i]) == false)
		return (false);
	j = 3;
	num = '1';
	tmp = g_arr[j][i];
	while (j-- >= 0)
	{
		if (tmp < g_arr[j][i])
		{
			tmp = g_arr[j][i];
			num++;
		}
	}
	return (num == g_condition[i + 4]);
}

bool	check_horizontal(int i, int j, char num)
{
	int tmp;

	tmp = g_arr[i - 4][j];
	while (j++ < 3)
	{
		if (tmp < g_arr[i - 4][j])
		{
			tmp = g_arr[i - 4][j];
			num++;
		}
	}
	if ((num == g_condition[i + 4]) == false)
		return (false);
	j = 3;
	num = '1';
	tmp = g_arr[i - 4][j];
	while (j-- >= 0)
	{
		if (tmp < g_arr[i - 4][j])
		{
			tmp = g_arr[i - 4][j];
			num++;
		}
	}
	return (num == g_condition[i + 8]);
}

bool	is_valid(int i)
{
	char	num;
	int		j;

	j = 0;
	num = '1';
	if (i < 4)
	{
		return (check_vertical(i, j, num));
	}
	else
	{
		return (check_horizontal(i, j, num));
	}
}
