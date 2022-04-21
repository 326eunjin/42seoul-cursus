/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:11:39 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 05:10:14 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				data;
	struct s_node	*llink;
	struct s_node	*rlink;
}	t_node;

typedef struct s_deque
{
	t_node		*front;
	t_node		*rear;
	size_t		size;
}	t_deque;

int	is_dup(t_deque *deque);
void	is_possible(char **argv);
long	long	ft_atoll(char *str);
void	parse_argv(t_deque *deque,char **argv);
void	push_back(t_deque *deque, int data);

int	pop_back(t_deque *deque);
void	init_stack(t_deque *deque);

void	push_front(t_deque *deque, int data);
int	pop_front(t_deque *deque);
void	swap(t_deque *a,t_deque *b, int status);
void print_error();
void	free_split(char **args);

int sort_check(t_deque *deque);
void	make_index(t_deque	*deque);
void free_deque(t_deque *deque);
void	print_pop_push_error(t_deque *deque);
void printDQ(t_deque *DQ);
int		ft_strcmp(const char *s1, const char *s2);
#endif