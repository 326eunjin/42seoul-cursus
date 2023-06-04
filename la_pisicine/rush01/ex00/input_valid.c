/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heehkim <heehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:56:25 by heehkim           #+#    #+#             */
/*   Updated: 2021/04/03 21:51:28 by chhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

extern char	g_condition[16];
extern char	g_arr[4][4];
extern int g_arr_num[8];
extern bool g_is_solve;

int		is_white_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int		is_valid_input(char *cond)
{
	int cnt;

	cnt = 0;
	while (*cond != '\0')
	{
		while (*cond && is_white_space(*cond))
			++cond;
		if (*cond)
		{
			if ('1' <= *cond && *cond <= '4')
			{
				if ((*(cond + 1) != '\0' && !is_white_space(*(cond + 1))))
					return (0);
				if (cnt == 16)
					return (0);
				g_condition[cnt++] = *cond;
			}
			else
				return (0);
			++cond;
		}
	}
	return (cnt == 16);
}
