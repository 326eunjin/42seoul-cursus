# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 20:10:08 by jeyoon            #+#    #+#              #
#    Updated: 2022/06/07 18:51:13 by jeyoon           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = test_parse
CFLAGS	=	-Wall -Wextra -Werror -lreadline -fsanitize=address

LIBFT_DIR = ./libft/
PARSE_DIR = ./parse/
BUILTIN_DIR = ./built_in/

LIBFT_SRCS = ft_memset.c ft_substr.c ft_strdup.c ft_strlcpy.c ft_strlen.c
PARSE_SRCS = main.c parse_analyze.c parse_cmd.c parse_token.c parse_util_token.c
BUILTIN_SRCS = 

SRCS = $(addprefix $(LIBFT_DIR), $(LIBFT_SRCS)) $(addprefix $(PARSE_DIR), $(PARSE_SRCS)) $(addprefix $(BUILTIN_DIR), $(BUILTIN_SRCS))
OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o	:	%.c
		$(CC) $(CFLAG) -c $< -o $@

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re	:	fclean all

.PHONY	:	all, clean, fclean, re