# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 14:40:05 by jeyoon            #+#    #+#              #
#    Updated: 2022/06/06 16:00:32 by jeyoon           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

C = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
INC = libft.h
SRCS1 = ft_isalnum.c ft_isprint.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c ft_atoi.c ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strlcat.c ft_strnstr.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c ft_calloc.c  ft_isdigit.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c 
SRCS2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_itoa.c ft_split.c ft_strmapi.c ft_putnbr_fd.c 

OBJS = $(SRCS1:.c=.o) $(SRCS2:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean
