# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejang <ejang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 20:10:08 by jeyoon            #+#    #+#              #
#    Updated: 2022/06/20 21:54:02 by ejang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = mini_test_shell
CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

LIBFT_DIR = ./libft/
PARSE_DIR = ./parse/
BUILTIN_DIR = ./built_in/
UTIL_DIR = ./util/
EXEC_DIR = ./exec/
REDIR_DIR = ./redirection/

LIBFT_SRCS = ft_memset.c ft_substr.c ft_strdup.c ft_strlcpy.c ft_strlen.c ft_isalnum.c ft_isalpha.c ft_split.c ft_strncmp.c ft_isdigit.c ft_strjoin.c ft_itoa.c ft_tolower.c ft_putstr_fd.c ft_atoi.c ft_putnbr_fd.c ft_putendl_fd.c ft_strlcat.c ft_putchar_fd.c
PARSE_SRCS = main.c parse_main.c parse_token.c parse_cmd.c parse_cmd_add.c parse_cmd_type.c parse_cmd_add_quote.c parse_cmd_utils.c
BUILTIN_SRCS = func_pwd.c func_env.c func_echo.c func_export.c func_unset.c func_cd.c func_cd_util.c func_exit.c
UTIL_SRCS = ft_strcmp.c copy_env.c tolowerstr.c set_signal.c free_split.c
EXEC_SRCS = exe_bulitin.c exe_cmd.c
REDIR_SRCS = redir_in.c without_redir.c redir_out.c

SRCS = $(addprefix $(LIBFT_DIR), $(LIBFT_SRCS)) $(addprefix $(PARSE_DIR), $(PARSE_SRCS)) $(addprefix $(BUILTIN_DIR), $(BUILTIN_SRCS)) $(addprefix $(UTIL_DIR), $(UTIL_SRCS)) $(addprefix $(EXEC_DIR), $(EXEC_SRCS)) $(addprefix $(REDIR_DIR), $(REDIR_SRCS))
OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			@$(CC) $(CFLAGS) -lreadline -L${HOME}/.brew/opt/readline/lib -o $@ $(OBJS)
			@printf "✅ \033[0;32m$(NAME) was created.\033[0m\n"

%.o	:	%.c
		@$(CC) $(CFLAG) -I${HOME}/.brew/opt/readline/include -c $< -o $@

clean	:
			@rm -rf $(OBJS)
			@printf "🚮 Object files were removed.\n"


fclean	:	clean
			@rm -rf $(NAME)
			@printf "🚮 $(NAME) was removed.\n"

re	:	fclean all

.PHONY	:	all, clean, fclean, re
