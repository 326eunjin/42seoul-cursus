/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:17:54 by ejang             #+#    #+#             */
/*   Updated: 2022/06/07 20:18:38 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

long	ft_atol(char *str)
{
	long		ret;
	int			minus;
	int			i;

	ret = 0;
	minus = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i])
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	if (minus == -1)
		ret = ret * minus;
	return (ret);
}

void func_exit(int argc,char **argv)
{
	int i = -1;
	long long first_argv;

	first_argv = ft_atol(argv[1]);
	if (argc == 1)
	{
		printf("exit\n");
		exit(g_exit_status);
	}
	else if (argc == 2 && first_argv >= -2147483648 && ft_atoi(argv[1]) <= 2147483647)
	{
		printf("exit\n");
		g_exit_status = ft_atoi(argv[1]);
		if (g_exit_status >= 0)
			g_exit_status = g_exit_status % 256;
		else
		{
			g_exit_status *= -1;
			g_exit_status = 256 - (g_exit_status % 256);
		}
		exit(g_exit_status);
	}
	else if (argc > 2  && first_argv >= -2147483648 && ft_atoi(argv[1]) <= 2147483647)
	{
		printf("exit\n");
		printf("bash: exit: too many arguments\n");
		g_exit_status = 1;
		return ;
	}
	else
	{
		printf("exit\n");
		printf("bash: exit: %s: numeric argument required\n",argv[1]);
		g_exit_status = 255;
		exit(g_exit_status);
	}
}
