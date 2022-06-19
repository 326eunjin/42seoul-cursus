/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:17:54 by ejang             #+#    #+#             */
/*   Updated: 2022/06/19 19:36:48 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

long	long	ft_atoll(char *str)
{
	long	long	ret;
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
		if (ft_isdigit(str[i]) == 0)
			return ((long long)INT_MAX + 1);
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	if (minus == -1)
		ret = ret * minus;
	return (ret);
}

//void func_exit(int argc,char **argv)
void	func_exit_single_cmd(t_cmd_node *head)
{
	int i = -1;
	long long first_argv;
	int cnt = 0;

	t_cmd_node *curr_node;//exit 
	curr_node = head;
	while(curr_node!=NULL)//exit cnt 1
	{
		cnt++;
		curr_node = curr_node->next;
	}
	if (cnt > 1)
		first_argv = ft_atoll(head->next->cmd);
	curr_node = head;//exit 가리킴 
	if (cnt == 1)//exit
	{
		printf("exit\n");
		exit(g_state.exit_status);
	}
	else if (cnt == 2 && first_argv >= INT_MIN && first_argv <= INT_MAX)//exit 숫자
	{
		printf("exit\n");
		g_state.exit_status = ft_atoi(curr_node->cmd);
		if (g_state.exit_status >= 0)
			g_state.exit_status = g_state.exit_status % 256;
		else
		{
			g_state.exit_status *= -1;
			g_state.exit_status = 256 - (g_state.exit_status % 256);
		}
		exit(g_state.exit_status);
	}
	else if (cnt > 2  && first_argv >= INT_MIN && first_argv <= INT_MAX)//exit 3 3 3 3 
	{
		ft_putstr_fd("exit\n",STDERR_FILENO);
		ft_putstr_fd("bash: exit: too many arguments\n",STDERR_FILENO);
		g_state.exit_status = 1;
		return ;
	}
	else//숫자가 아닌게 하나라도 들어오면 
	{
		ft_putstr_fd("exit\n",STDERR_FILENO);
		ft_putstr_fd("bash: exit: ",STDERR_FILENO);
		ft_putstr_fd(curr_node->cmd, STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		g_state.exit_status = 255;
		exit(g_state.exit_status);
	}
}

void	func_exit(t_cmd_node *head)
{
	int i = -1;
	long long first_argv;
	int cnt = 0;
	t_cmd_node *curr_node;//exit 
	curr_node = head;
	while(curr_node!=NULL)//exit cnt 1
	{
		cnt++;
		curr_node = curr_node->next;
	}
	if (cnt > 1)
		first_argv = ft_atoll(head->next->cmd);
	curr_node = head;//exit 가리킴 
	if (cnt == 1)//exit
		exit(g_state.exit_status);
	else if (cnt == 2 && first_argv >= INT_MIN && first_argv <= INT_MAX)//exit 숫자
	{
		g_state.exit_status = ft_atoi(curr_node->cmd);
		if (g_state.exit_status >= 0)
			g_state.exit_status = g_state.exit_status % 256;
		else
		{
			g_state.exit_status *= -1;
			g_state.exit_status = 256 - (g_state.exit_status % 256);
		}
		exit(g_state.exit_status);
	}
	else if (cnt > 2  && first_argv >= INT_MIN && first_argv <= INT_MAX)//exit 3 3 3 3 
	{
		ft_putstr_fd("bash: exit: too many arguments\n",STDERR_FILENO);
		g_state.exit_status = 1;
		return ;
	}
	else//숫자가 아닌게 하나라도 들어오면 
	{
		ft_putstr_fd("bash: exit: ",STDERR_FILENO);
		ft_putstr_fd(curr_node->cmd, STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		g_state.exit_status = 255;
		exit(g_state.exit_status);
	}
}