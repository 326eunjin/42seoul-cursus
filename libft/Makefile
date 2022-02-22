# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/04 10:13:38 by ejang             #+#    #+#              #
#    Updated: 2022/02/23 03:28:53 by ejang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRCS := ft_itoa.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c 
SRCS_B := 

OBJS = $(SRCS:.c=.o)
BOBJS = $(SRCS_B:.c=.o)
 AR := ar
 ARFLAGS := -rc
 CC := gcc
 CFLAGS := -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(BOBJS)
else
	OBJECTS = $(OBJS)
endif

.PHONY:		all bonus clean fclean re
all:		$(NAME)
$(NAME):	$(OBJECTS)
	ar -rc $@ $^
bonus:
	make WITH_BONUS=1 all
%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(BOBJS)
fclean:		clean
	rm -f $(NAME)
re:			fclean all
