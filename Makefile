# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 20:10:08 by jeyoon            #+#    #+#              #
#    Updated: 2022/06/26 00:04:15 by jeyoon           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = minishell
CFLAGS	=	-Wall -Wextra -Werror

LIBFT_DIR = ./libft/
PARSE_DIR = ./parse/
BUILTIN_DIR = ./built_in/
UTIL_DIR = ./util/
EXEC_DIR = ./exec/
REDIR_DIR = ./redirection/

PARSE_SRCS = parse_cmd_utils2.c parse_main.c parse_token.c parse_cmd.c parse_cmd_add.c parse_cmd_type.c parse_cmd_add_quote.c parse_cmd_utils.c
BUILTIN_SRCS = func_pwd.c func_env.c func_echo.c func_export.c func_unset.c func_cd.c func_cd_util.c func_exit.c func_export_util.c func_cd_single.c func_unset_single.c
UTIL_SRCS = ft_strcmp.c copy_env.c tolowerstr.c signal_set.c signal_handler.c free.c parse_utils.c
EXEC_SRCS = exe_bulitin.c exe_cmd_util.c exe_cmd_with_pipe.c exe_cmd_without_pipe.c exe_cmd_with_pipe_util.c
REDIR_SRCS = redir_in.c without_redir.c redir_out.c heredoc.c heredoc_utils.c

SRCS = main.c $(addprefix $(PARSE_DIR), $(PARSE_SRCS)) $(addprefix $(BUILTIN_DIR), $(BUILTIN_SRCS)) $(addprefix $(UTIL_DIR), $(UTIL_SRCS)) $(addprefix $(EXEC_DIR), $(EXEC_SRCS)) $(addprefix $(REDIR_DIR), $(REDIR_SRCS))
OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			@make -C $(LIBFT_DIR) all
			@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft -lreadline -L${HOME}/.brew/opt/readline/lib -o $@ $(OBJS)
			@printf "✅ \033[0;32m$(NAME) was created.\033[0m\n"

%.o	:	%.c
		@$(CC) $(CFLAG) -I${HOME}/.brew/opt/readline/include -c $< -o $@

clean	:
			@rm -rf $(OBJS)
			@make -C $(LIBFT_DIR) clean
			@printf "🚮 $(NAME)'s object files were removed.\n"


fclean	:	clean
			@rm -rf $(NAME)
			@make -C $(LIBFT_DIR) fclean
			@printf "🚮 $(NAME) was removed.\n"

re	:	fclean all

.PHONY	:	all, clean, fclean, re
