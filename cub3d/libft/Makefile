# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/04 10:13:38 by ejang             #+#    #+#              #
#    Updated: 2022/06/22 21:14:32 by jeyoon           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRCS := ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 
SRCS_B := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
				ft_lstmap.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(SRCS_B:.c=.o)
 AR := ar
 ARFLAGS := -rc
 CC := cc
 CFLAGS := -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(BOBJS)
else
	OBJECTS = $(OBJS)
endif

.PHONY:		all bonus clean fclean re
all:		$(NAME)
$(NAME):	$(OBJECTS)
	@ar -rc $@ $^
	@printf "✅ \033[0;32m$(NAME) was created.\033[0m\n"
bonus:
	make WITH_BONUS=1 all
%.o:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJS) $(BOBJS)
	@printf "🚮 $(NAME)'s object files were removed.\n"
fclean:		clean
	@rm -f $(NAME)
	@printf "🚮 $(NAME) was removed.\n"
re:			fclean all
