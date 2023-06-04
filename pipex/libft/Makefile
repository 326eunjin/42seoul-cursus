# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/04 10:13:38 by ejang             #+#    #+#              #
#    Updated: 2022/03/31 07:04:32 by ejang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRCS := ft_split.c ft_strjoin.c ft_strdup.c ft_strncmp.c ft_strlcpy.c ft_strlen.c ft_strchr.c ft_strnstr.c 

OBJS = $(SRCS:.c=.o)
 AR := ar
 ARFLAGS := -rc
 CC := gcc
 CFLAGS := -Wall -Wextra -Werror
OBJECTS = $(OBJS)

.PHONY:		all bonus clean fclean re
all:		$(NAME)
$(NAME):	$(OBJECTS)
	ar -rc $@ $^
%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) 
fclean:		clean
	rm -f $(NAME)
re:			fclean all
