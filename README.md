# printf

[printf.pdf](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d3b8ccc7-8642-4eb1-b2fd-4d9e61d59334/printf.pdf)

[](https://github.com/326eunjin/printf.git)

“*This project is pretty straight forward. You will recode printf. Hopefully you
will be able to reuse it in future projects without the fear of being flagged as a cheater.
You will mainly learn how to use variadic arguments.”*

---

## 코드 짜기 전

- 가변 인자 함수
    - 함수의 매개변수 개수가 정해져 있지 않은 함수 ex.printf
    - int printf(const char restruct *format, ...); → printf 함수 원형
    - 가변인자 함수 생성 시 <stdarg.h> 헤더 추가
        - va_list : 가변 인자 목록. 가변 인자의 메모리 주소를 저장하는 포인터입니다.
        - va_start : 가변 인자를 가져올 수 있도록 포인터를 설정합니다.
        - va_arg : 가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져옵니다.
        - va_end : 가변 인자 처리가 끝났을 때 포인터를 NULL로 초기화합니다.
- printf 함수 서식지정자
    
    
    | c | 문자 |
    | --- | --- |
    | s | 문자열 |
    | p | 포인터의 메모리 주소 |
    | d | 부호 있는 10진 정수 |
    | i | 부호 있는 10진 정수 |
    | u | 부호 없는 10진 정수 |
    | x | 부호 없는 16진 정수(소문자) |
    | X | 부호 없는 16진 정수(대문자) |
    | % | % 기호 출력 |
- 헤더
    
    ```c
    #ifndef HEADER_H
    # define HEADER_H
    
    [include할 다른 헤더 파일 명시]
    
    [매크로 정의]
    
    [사용자 struct, type 정의]
    
    [전역 변수 선언]
    
    [함수 선언]
    
    #endif
    ```
    

## 서브젝트 분석

| c | 문자 | 그냥 출력 |
| --- | --- | --- |
| s | 문자열 | 이 역시도 그대로 출력 단, 문자열이 없는 경우, (null)이 출력되며 6이 리턴된다. |
| p | 포인터의 메모리 주소 | 이게 좀 어려웠는데.. 포인터 주소를 출력하는 것이니 unsigned long long으로 들어온 포인터 주소를 16진수로 변환하여 출력하면 된다.
https://waintman.tistory.com/55 (왜 unsigned long long인지에 대한 설명) |
| d | 부호 있는 10진 정수 | 문자열 함수 출력 그대로 활용 |
| i | 부호 있는 10진 정수 | 문자열 함수 출력 그대로 활용 |
| u | 부호 없는 10진 정수 | x X 출력하는 것과 동일 단, 16진수가 아니므로 10으로 나누면서 출력(재귀 및 반복문 호출) |
| x | 부호 없는 16진 정수(소문자) | 16진수로 변환하여 출력 대신 소문자로(재귀 및 반복문 사용) |
| X | 부호 없는 16진 정수(대문자) | 16진수로 변환하여 출력 대신 대문자로 (재귀 및 반복문 호출) |
| % | % 기호 출력 | %% 이렇게 나와야 하므로 %%가 연속으로 나올 경우 % write 함수로 출력 |
- printf 함수의 리턴 값은 몇바이트를 읽었는지 즉, 읽은 바이트 수만큼 리턴한다.
- **ft_printf 함수에는 올바른 값만 들어온다고 가정한다. 즉, 에러핸들링은 최소한으로 고려한다.**
- 전반적인 구상
    - 들어온 문자열에 %이 있는지 while문을 돌면서 확인한다
        - %가 있을 경우(형식에 맞게 출력)
            - 그 다음 문자가  csupidxX%인지 확인한다 (과제에서 주어진 형식에 부합하는지 확인)
                - 형식지정자가 있으면
                    - 형식에 맞는 함수 호출(ex %c의 경우, ft_print_char(char c) 호출)
                    - 출력함과 동시에 count도 읽은 바이트 수만큼 늘린다.
                - 형식지정자가 없으면
                    - 에러임으로 -1을 리턴하면서 함수 종료
        - %가 없을 경우(그대로 출력)
            - 문자하나하나  그대로 출력한다
            - 출력함과 동시에 count++;를 시킨다.

## 코드

```c
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_print_str(char *str);//문자열 출력
int		ft_print_nbr(int nbr);//부호 있는 10진 정수 출력
int		ft_print_unnbr(unsigned int nbr);//부호 없는 10진 정수 출력
int		ft_print_pointer(unsigned long long pointer);//포인터변수 출력
int		ft_print_hex_upper2(unsigned int nbr);//16진수 출력 대문자
int		ft_print_hex_lower2(unsigned int nbr);//16진수 출력 소문자

#endif
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:39:52 by ejang             #+#    #+#             */
/*   Updated: 2022/02/23 02:52:54 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_getlen(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

static	char	*ft_print_hex_lower1(unsigned int nbr)
{
	int		i;
	int		temp;
	int		size;
	char	*tmp;

	i = 0;
	size = ft_getlen(nbr);
	tmp = malloc(sizeof(char) * (size + 1));
	if (tmp == NULL)
		return (0);
	tmp[size] = '\0';
	while (--size >= 0)
	{
		temp = nbr % 16 ;
		nbr = nbr / 16;
		if (temp > 9)
			tmp[size] = (temp + 87);
		else
			tmp[size] = (temp + '0');
	}
	return (tmp);
}

int	ft_print_hex_lower2(unsigned int nbr)
{	
	int		ret;
	int		i;
	char	*tmp;

	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	tmp = ft_print_hex_lower1(nbr);
	ret = ft_print_str(tmp);
	free(tmp);
	return (ret);
}

static	char	*ft_print_hex_upper1(unsigned int nbr)
{
	int		i;
	int		temp;
	int		size;
	char	*tmp;

	i = 0;
	size = ft_getlen(nbr);
	tmp = malloc(sizeof(char) * (size + 1));
	if (tmp == NULL)
		return (0);
	tmp[size] = '\0';
	while (--size >= 0)
	{
		temp = nbr % 16 ;
		nbr = nbr / 16;
		if (temp > 9)
			tmp[size] = (temp + 55);
		else
			tmp[size] = (temp + '0');
	}
	return (tmp);
}

int	ft_print_hex_upper2(unsigned int nbr)
{	
	int		ret;
	int		i;
	char	*tmp;

	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	tmp = ft_print_hex_upper1(nbr);
	ret = ft_print_str(tmp);
	free(tmp);
	return (ret);
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:39:52 by ejang             #+#    #+#             */
/*   Updated: 2022/02/22 23:10:04 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int nbr)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(nbr);
	len = ft_print_str(num);
	free(num);//itoa에서 malloc함수를 쓰기 때문에 여기서 해제해줌.
	return (len);
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:51:26 by ejang             #+#    #+#             */
/*   Updated: 2022/02/23 12:55:53 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(unsigned long long nb)
{
	if (nb >= 16)//재귀문
	{
		ft_putptr(nb / 16);
		nb %= 16;
	}
	if (nb > 9)//10 11 12 13 14 15 대신, a b c d e f 출력
		ft_putchar_fd(nb + 87, 1);
	else
		ft_putchar_fd(nb + '0', 1);//숫자 대신 문자 형식으로 출력해야 하므로 '0'를 더함
}

static int	ft_sizeptr(unsigned long long nbr)//%p로 출력했을 때 몇 바이트인지 확인
{
	int	size;

	size = 2;//0x 
	if (nbr == 0)//0x0 -> 3 리턴
		size++;
	while (nbr > 0)//즉, 소위 말해 몇칸인지 반복문을 돌면서 확인
	{
		nbr = nbr / 16;
		size++;
	}
	return (size);
}

int	ft_print_pointer(unsigned long long nbr)
{
	ft_putstr_fd("0x", 1);//%p의 경우 0x 출력
	ft_putptr(nbr);
	return (ft_sizeptr(nbr));
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:36:30 by ejang             #+#    #+#             */
/*   Updated: 2022/02/22 23:10:14 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	if (!str)//문자열이 비었으면 널 처리 
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);//문자열 그대로 출력 libft에서 가져온 함수
	return (ft_strlen(str));//몇바이트 읽었는지 리턴
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:39:52 by ejang             #+#    #+#             */
/*   Updated: 2022/02/23 00:31:57 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unnbr(unsigned int n)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		print_length += ft_print_str(num);
		free(num);
	}
	return (print_length);
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:17:08 by ejang             #+#    #+#             */
/*   Updated: 2022/02/23 02:38:49 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)//문자 출력
{
	write(1, &c, 1);
	return (1);
}

static int	print_format(char ch, va_list *ap)//형식에 맞게 함수 호출, 대신 len= 함수인
//함수에서 몇 바이트 읽었는지 리턴하기 때문
{
	int	len;

	len = 0;
	if (ch == 'c')
		len = ft_print_char(va_arg(ap, int));
	if (ch == 's')
		len = ft_print_str(va_arg(ap, char *));
	else if (ch == 'p')
		len = ft_print_pointer(va_arg(ap, unsigned long long));
	else if (ch == 'd' || ch == 'i')
		len = ft_print_nbr(va_arg(ap, int));
	else if (ch == 'u')
		len = ft_print_unnbr(va_arg(ap, unsigned int));
	else if (ch == 'x')
		len = ft_print_hex_lower2(va_arg(ap, unsigned int));
	else if (ch == 'X')
		len = ft_print_hex_upper2(va_arg(ap, unsigned int));
	else if (ch == '%')//이 경우, %%이므로 %가 출력되어야한다.
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

static char	is_valid_format(char ch)//형식지정자에 맞게 제대로들어왔는지 확인
{
	if (ch == 'c' || ch == 's' || ch == 'p'
		|| ch == 'd' || ch == 'i' || ch == 'u'
		|| ch == 'x' || ch == 'X' || ch == '%')
		return (1);
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')//문자열을 돌면서
	{
		if (str[i] == '%')//%가 있는지 확인
		{
			if (!is_valid_format(str[i + 1]))//%가 있으면 그 뒤에 서브젝트에서 주어진 형식이 들어오는지 확인 
				return (-1);//형식이 올바르지 않으면 에러핸들링 -1 리턴하고 종료
			count += print_format(str[i + 1], ap);
			i += 2;
		}
		else//%가 없으면
		{
			count += ft_print_char(str[i]);
			i++;
		}
	}
	va_end(ap);
	return (count);
}
```

```c
NAME = libftprintf.a

CC = gcc

INCLUDE = -I ./include

CFLAGS = -Wall -Werror -Wextra $(INCLUDE) 

SRC = ./src/

MAIN = $(addprefix $(SRC), \
	ft_printf.c ft_print_hex.c ft_print_nbr.c \
	ft_print_pointer.c ft_print_str.c ft_print_unnbr.c)

OBJ = $(MAIN:%.c=%.o)

$(NAME): $(OBJ)
	make all -C ./libft
	cp ./libft/libft.a libftprintf.a
	ar -rcs $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf ./a.out
	make clean -C ./libft

fclean:	clean
	rm -rf $(NAME)
	make fclean -C ./libft

re:	fclean all
```

- [https://42kchoi.tistory.com/13](https://42kchoi.tistory.com/13) //ㄱ ㅏ변인
- 0이 아닌 모든 값이 참
- [https://hahoital.tistory.com/140](https://hahoital.tistory.com/140)
