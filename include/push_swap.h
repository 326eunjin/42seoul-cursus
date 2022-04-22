/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:11:39 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 16:20:28 by ejang            ###   ########.fr       */
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
	int				tmp;
	struct s_node	*llink;
	struct s_node	*rlink;
}	t_node;

typedef struct s_deque
{
	t_node		*front;
	t_node		*rear;
	size_t		size;
}	t_deque;

int			ft_strcmp(const char *s1, const char *s2);
int			is_dup(t_deque *deque);
void		is_possible(char **argv);
long long	ft_atoll(char *str);
void		parse_argv(t_deque *deque, char **argv);

void		push_top(t_deque *deque, int data);
int			pop_top(t_deque *deque);
void		rotate(t_deque *deque);
void		reverse_rotate(t_deque *deque);

void		init_stack(t_deque *deque);
void		push_bottom(t_deque *deque, int data);
int			pop_bottom(t_deque *deque);
void		swap(t_deque *deque);
void		push(t_deque *deque1, t_deque *deque2);

void		print_error(void);
void		print_pop_push_error(t_deque *deque);
void		free_deque(t_deque *deque);
void		free_split(char **args);

void		ss(t_deque *a, t_deque *b);
void		rr(t_deque *a, t_deque *b);
void		rrr(t_deque *a, t_deque *b);
void		instruct(t_deque *a, t_deque *b, char *inst);

void		push_swap(t_deque *a, t_deque *b);

void		sort_little_three(t_deque *a);
void		sort_little_five(t_deque *a, t_deque *b);
void		sort_little(t_deque *a, t_deque *b);

int			sort_check(t_deque *deque);
void		make_index(t_deque	*deque);
void		make_index_deque(t_deque *deque);

void		printDQ(t_deque *DQ);

#endif