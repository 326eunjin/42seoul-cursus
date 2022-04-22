/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:02:10 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 19:29:25 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_dup(t_deque *deque)
{
	t_node	*ptr1;
	t_node	*ptr2;

	ptr1 = deque->front;
	while (ptr1 != NULL)
	{
		ptr2 = ptr1->rlink;
		while (ptr2 != NULL)
		{
			if (ptr1->data == ptr2->data)
				return (-1);
			ptr2 = ptr2->rlink;
		}
		ptr1 = ptr1->rlink;
	}
	return (0);
}

void	is_possible(char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (*argv == NULL || !argv)
		print_error();
	while (argv[i] != 0)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9') || \
				(argv[i][j] == '+' || argv[i][j] == '-')))
				print_error();
			if ((argv[i][j] == '+' || argv[i][j] == '-') && \
				(argv[i][j + 1] == '\0'))
				print_error();
			if (j > 0 && (argv[i][j] == '+' || argv[i][j] == '-'))
				print_error();
			j++;
		}
		i++;
	}
}

long	long	ft_atoll(char *str)
{
	long long	ret;
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

void	parse_argv(t_deque *deque, char **argv)
{
	int			i;
	int			j;
	char		**arr;
	long long	num;

	i = 1;
	while (argv[i] != 0)
	{
		if (ft_strcmp(argv[i], "") == 0)
			print_error();
		j = 0;
		arr = ft_split(argv[i++], ' ');
		is_possible(arr);
		while (arr[j] != 0)
		{
			num = ft_atoll(arr[j++]);
			if (num > INT_MAX || num < INT_MIN)
				print_error();
			push_bottom(deque, (int)num);
		}
		free_split(arr);
	}
}
