# Push_swap

[push_swap.pdf](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/01a5daee-43a0-4673-9046-e5fd82ab95a0/push_swap.pdf)

[](https://github.com/326eunjin/push_swap)

*“This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting”*

---

## 서브젝트 분석

- 2개의 스택이 있다 (a 스택 b 스택)
- 스택 a에는 랜덤한 숫자들 (양수 음수 다 포함)이 중복없이 있다.
- 스택  b는 비어있다.
- 본 과제의 목표는 스택 a에 오름차순으로 정렬하는 것이다.
- sa (swap a) : a 스택의 상위 두 요소를  바꾸는 것이다.
- sb (swap b) : b 스택의 상위 두 요소를  바꾸는 것이다.
- ss : sa와 sb를 둘다 동시에 한다.
- pa (push a) : b 스택의 맨 위에 있는 요소를 빼고 a 스택의 상단에 넣는다. (다만 b 스택이 비어 있는 경우, 아무 것도 하지 않는다.)
- pb (push b) : a 스택의 맨 위에 있는 요소를 빼고 b 스택의 상단에 넣는다. (다만 a 스택이 비어 있는 경우, 아무 것도 하지 않는다.)
- ra(rotate a) : a 스택을 위로 한 칸씩 이동한다. 이 경우, 맨 위 요소가 맨 밑으로 간다.
- rb(rotate b) : b 스택을 위로 한 칸씩 이동한다. 이 경우, 맨 위 요소가 맨 밑으로 간다.
- rr : ra와 rb를 동시에 한다.
- rra(reverse rotate a) : a 스택을 밑으로 한 칸씩 이동한다. 이 경우, 맨 밑 요소가 맨 위로 간다.
- rrb(reverse rotate b) : a 스택을 밑으로 한 칸씩 이동한다. 이 경우, 맨 밑 요소가 맨 위로 간다.
- rrr : rra와 rrb를 동시에 한다.

## 코드 구상

- 말이 스택이지만, rrr와 rr을 생각해서 deque라는 자료구조를 사용했다.(double ended queue)
    
![image](https://user-images.githubusercontent.com/50578785/176637911-da8fafef-81ab-4cab-b88b-c2f9ae08c51c.png)
    
- 알고리즘은 모래 시계를 이용했다.
    - 큰 틀
        
        가 : 스택 a에 있는 값을 모두 다 b로 넘기기
        
        나 : 스택 b의 가장 큰 값을 top으로 올려서 그 값부터 a로 넘기기
        
        다 : 정렬 끝
        
    - 세부 규칙
        
        num의 값을 0이라 하고 chunk 라는 상수가 15 (전체 size 가 500개일 때는 30)로 임의로 정합니다
        
        top의 값을 다음의 세 구간으로 구분하여 처리합니다.
        
        top이 num보다 작을때 넘기고 , num + chunk 사이일때만 B로 넘기고 한번 뒤집고 num + chunk 보다 클때는 B로 넘기지 않는다.
        
- 코드 로직
    - a 스택 초기화
    - 파싱
    - 인덱싱하기
    - b 스택 초기화
    - 모래 시계
    - 스택 해제

## 코드

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:11:39 by ejang             #+#    #+#             */
/*   Updated: 2022/05/02 13:24:22 by ejang            ###   ########.fr       */
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
	int				data;//기존 파싱한 데이터
	int				tmp;//인덱싱 한 숫자
	struct s_node	*llink;
	struct s_node	*rlink;
}	t_node;

typedef struct s_deque
{
	t_node		*front;
	t_node		*rear;
	int			size;
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
int			get_top_element(t_deque *deque);

void		init_deque(t_deque *deque);
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
int			get_chunk(t_deque *a);
void		put_a_to_b(t_deque *a, t_deque *b, int chunk);
void		put_b_to_a(t_deque *a, t_deque *b);
int			find_max(t_deque *b);
int			find_loc(int max, t_deque *deque);
void		move_big_top(t_deque *b);

void		sort_little_three(t_deque *a);
void		sort_little_five(t_deque *a, t_deque *b);
void		sort_little(t_deque *a, t_deque *b);

int			sort_check(t_deque *deque);
void		make_index(t_deque	*deque);
void		make_index_deque(t_deque *deque);

#endif
```

```c
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
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_front.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:31:40 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 19:54:11 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_deque(t_deque *deque)//덱 초기화
{
	deque->rear = NULL;
	deque->front = NULL;
	deque->size = 0;
}

void	push_bottom(t_deque *deque, int data)//맨 밑에 노드 삽입
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));//할당
	new->tmp = 0;
	new->data = data;//초기화
	if (deque->size == 0)//노드가 0 즉, 덱이 빈 덱
	{	
		deque->rear = new;
		deque->front = new;
		deque->size++;
		new->llink = NULL;
		new->rlink = NULL;
	}
	else//빈 덱이 아니라면
	{
		deque->front->llink = new;//덱의 처음 노드에 새로운 노드 연결
		new->rlink = deque->front;
		new->llink = NULL;
		deque->front = new;
		deque->size++;
	}
}

int	pop_bottom(t_deque *deque)//맨 밑 노드 삭제
{
	t_node	*del;
	int		ret;

	ret = 0;
	del = deque->front;//첫번째 노드 가리킴
	del->tmp = 0;
	if (deque->size == 0)
		print_pop_push_error(deque);
	ret = del->data;
	if (deque->front->rlink == NULL)//기존에 하나의 노드만 있었으면 노드 삭제 후 아무것도 없음
	{
		deque->front = NULL;
		deque->rear = NULL;
	}
	else
	{
		deque->front = deque->front->rlink;
		deque->front->llink = NULL;
	}
	free(del);
	deque->size--;
	return (ret);
}

void	swap(t_deque *deque)//swap 즉, 각 스택의 맨 위 노드 삭제하고 각각을 반대의 스택에 삽입.
{
	int	tmp1;
	int	tmp2;

	tmp1 = pop_top(deque);
	tmp2 = pop_top(deque);
	push_top(deque, tmp1);
	push_top(deque, tmp2);
}

void	push(t_deque *deque1, t_deque *deque2)//삽입은 다른 스택의 맨위 노드를 삭제 후 다른 스택에 삽입
{
	int	tmp;

	tmp = pop_top(deque2);
	push_top(deque1, tmp);
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:36:02 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 19:53:45 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_top(t_deque *deque, int data)//맨 위 노드 삽입
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->tmp = 0;
	new->data = data;
	if (deque->size == 0)
	{
		deque->front = new;
		deque->rear = new;
		new->rlink = NULL;
		new->llink = NULL;
		deque->size++;
	}
	else
	{
		deque->rear->rlink = new;
		new->rlink = NULL;
		new->llink = deque->rear;
		deque->rear = new;
		deque->size++;
	}
}

int	pop_top(t_deque *deque)//맨 위 노드 삭제
{
	t_node	*del;
	int		ret;

	ret = 0;
	del = deque -> rear;
	del->tmp = 0;
	if (deque->size == 0)
		print_pop_push_error(deque);
	ret = del->data;
	if (deque->rear->llink == NULL)
	{
		deque->front = NULL;
		deque->rear = NULL;
	}
	else
	{
		deque->rear = deque->rear->llink;
		deque->rear->rlink = NULL;
	}
	free(del);
	deque->size--;
	return (ret);
}

void	rotate(t_deque *deque)//맨 위 노드 삭제 후 해당 노드 맨 밑에 삽입
{
	int	tmp;

	tmp = pop_top(deque);
	push_bottom(deque, tmp);
}

void	reverse_rotate(t_deque *deque)//맨 밑 노드 삭제 후 해당 노드를 맨 위에 삽입
{
	int	tmp;

	tmp = pop_bottom(deque);
	push_top(deque, tmp);
}

int	get_top_element(t_deque *deque)//맨 위 노드의 데이터 값을 얻음
{
	int	item;

	if (deque->size == 0)
		return (0);
	item = deque->rear->data;
	return (item);
}
```

```c
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

int	ft_strcmp(const char *s1, const char *s2)//문자열 비교
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_dup(t_deque *deque)//중복인지? 중복이 아니라면 0 리턴
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
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:08:44 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 06:15:45 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	print_pop_push_error(t_deque *deque)
{
	free_deque(deque);
	write(1, "cannot push or pop\n", 19);
	exit(1);
}

void	free_deque(t_deque *deque)
{
	t_node	*tmp;

	deque->rear = NULL;
	while (deque->front != NULL)
	{
		tmp = deque->front;
		deque->front = deque->front->rlink;
		free(tmp);
	}
	deque->size = 0;
}

void	free_split(char **args)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (args[size])
		size++;
	while (i < size)
		free(args[i++]);
	free(args);
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 06:50:52 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 19:54:32 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_deque *a, t_deque *b)
{
	swap(a);
	swap(b);
}

void	rr(t_deque *a, t_deque *b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_deque *a, t_deque *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	instruct(t_deque *a, t_deque *b, char *inst)
{
	if (ft_strcmp("sa", inst) == 0)
		swap(a);
	else if (ft_strcmp("sb", inst) == 0)
		swap(b);
	else if (ft_strcmp("ss", inst) == 0)
		ss(a, b);
	else if (ft_strcmp("pa", inst) == 0)
		push(a, b);
	else if (ft_strcmp("pb", inst) == 0)
		push(b, a);
	else if (ft_strcmp("ra", inst) == 0)
		rotate(a);
	else if (ft_strcmp("rb", inst) == 0)
		rotate(b);
	else if (ft_strcmp("rr", inst) == 0)
		rr(a, b);
	else if (ft_strcmp("rra", inst) == 0)
		reverse_rotate(a);
	else if (ft_strcmp("rrb", inst) == 0)
		reverse_rotate(b);
	else if (ft_strcmp("rrr", inst) == 0)
		rrr(a, b);
	ft_putstr_fd(inst, 1);
	ft_putstr_fd("\n", 1);
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:02:47 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 22:14:32 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_max(t_deque *b)
{
	int		ret;
	t_node	*temp;

	temp = b->rear;
	ret = temp->data;
	while (temp)
	{
		if (temp->data > ret)
			ret = temp->data;
		temp = temp->llink;
	}
	return (ret);
}

int	find_loc(int max, t_deque *deque)
{
	int		ret;
	t_node	*temp;

	temp = deque->front;
	ret = 0;
	while (temp)
	{
		ret++;
		if (temp->data == max)
			break ;
		temp = temp->rlink;
	}
	if (ret <= deque->size / 2)
		return (0);
	return (1);
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 06:03:48 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 22:34:58 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_deque *a, t_deque *b)
{
	int	chunk;

	if (a->size <= 5 && a->size != 4)//4개 미만이면 하드코딩
	{
		sort_little(a, b);
		free_deque(a);
		free_deque(b);
		exit(0);
	}
	chunk = get_chunk(a);
	put_a_to_b(a, b, chunk);
	put_b_to_a(a, b);
}

int	get_chunk(t_deque *a)
{
	int	ret;

	ret = 0.000000053 * (a->size) * (a->size) + 0.03 * (a->size) + 14.5;
	return (ret);
}

void	put_a_to_b(t_deque *a, t_deque *b, int chunk)//a를 b로 넘기기
{
	int	num;
	int	top;

	num = 0;
	while (a->size != 0)
	{
		top = get_top_element(a);
		if (top <= num)
		{
			instruct(a, b, "pb");
			num++;
		}
		else if (num + chunk < top)
			instruct(a, b, "ra");
		else
		{
			instruct(a, b, "pb");
			instruct(a, b, "rb");
			num++;
		}
	}
}

void	put_b_to_a(t_deque *a, t_deque *b)//b의 가장 큰 값을 찾아서 걔를 a로 이동
{
	while (b->size != 0)
	{
		move_big_top(b);
		instruct(a, b, "pa");
	}
}

void	move_big_top(t_deque *b)
{
	int	max;

	max = find_max(b);
	if (find_loc(max, b) == 1)
	{
		while (get_top_element(b) != max)
		{
			instruct(NULL, b, "rb");
			max = find_max(b);
		}
	}
	else
	{
		while (get_top_element(b) != max)
		{
			instruct(NULL, b, "rrb");
			max = find_max(b);
		}
	}
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:46:11 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 22:13:26 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_little_three(t_deque *a)//하드코딩
{
	int	first;
	int	second;
	int	third;

	first = a->front->data;
	second = a->front->rlink->data;
	third = a->front->rlink->rlink->data;
	if (first < second && second < third && first < third)
	{
		instruct(a, NULL, "sa");
		instruct(a, NULL, "rra");
	}
	if (first < second && second > third && first < third)
		instruct(a, NULL, "rra");
	if (first > second && second < third && first < third)
		instruct(a, NULL, "ra");
	if (first < second && second > third && first > third)
	{
		instruct(a, NULL, "rra");
		instruct(a, NULL, "sa");
	}
	if (first > second && second < third && first > third)
		instruct(a, NULL, "sa");
}

void	sort_little(t_deque *a, t_deque *b)
{
	if (a->size == 2)
		instruct(a, NULL, "sa");
	if (a->size == 3)
		sort_little_three(a);
	else
		sort_little_five(a, b);
}

void	sort_little_five(t_deque *a, t_deque *b)//5개의 경우, 중간의 값보다 작으면 pb 나머지는 ra
//그래서 가장 큰 값 3개만 a에 남아있고 b에는 가장 작은 값 2개가 남아있다.
//각각 정렬
{
	int	mid;
	int	pb;

	pb = 0;
	mid = 2;
	while (1)
	{
		if (get_top_element(a) < mid)
		{
			instruct(a, b, "pb");
			pb++;
		}
		else
			instruct(a, b, "ra");
		if (pb == 2)
			break ;
	}
	sort_little_three(a);
	if (b->front->data > b->front->rlink->data)
		instruct(NULL, b, "sb");
	instruct(a, b, "pa");
	instruct(a, b, "pa");
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:45:50 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 19:58:18 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_check(t_deque *deque)
{
	t_node	*ptr1;
	t_node	*ptr2;

	ptr1 = deque->front;
	while (ptr1 != NULL)
	{
		ptr2 = ptr1->rlink;
		while (ptr2 != NULL)
		{
			if (ptr1->data < ptr2->data)
				return (0);
			ptr2 = ptr2->rlink;
		}
		ptr1 = ptr1->rlink;
	}
	return (1);
}

void	make_index(t_deque	*deque)//최적화를 위해 0 1 9999 2 를 0 1 3 2로 치환
{
	t_node	*ptr1;
	t_node	*ptr2;

	ptr1 = deque->front;
	while (ptr1 != NULL)
	{
		ptr2 = deque->front;
		while (ptr2 != NULL)
		{
			if (ptr1->data > ptr2->data)
				ptr1->tmp++;
			ptr2 = ptr2->rlink;
		}
		ptr1 = ptr1->rlink;
	}
	make_index_deque(deque);
}

void	make_index_deque(t_deque *deque)
{
	t_node	*temp;

	temp = deque->front;
	while (temp)
	{
		temp->data = temp->tmp;
		temp->tmp = 0;
		temp = temp->rlink;
	}
}
```
