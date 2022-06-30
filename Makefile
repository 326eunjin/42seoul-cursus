# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejang <ejang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 20:10:08 by jeyoon            #+#    #+#              #
#    Updated: 2022/06/30 15:46:30 by ejang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	 = cc
NAME = fractol
CFLAGS	=	-Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit
LIBFT_DIR = ./libft/
MLX_DIR = ./mlx/
SRC_DIR = ./src/
HEADER = -Iincludes
SRC_SRCS= draw.c error.c event.c ft_atod.c init_fractol.c julia_mandelbrot.c main.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_SRCS)) 
OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			@make -C $(LIBFT_DIR) all
			@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX_FLAGS) -o $@ $(OBJS)
			@printf "✅ \033[0;32m$(NAME) was created.\033[0m\n"

%.o	:	%.c
		@$(CC) $(CFLAG) $(HEADER) -c $< -o $@

clean	:
			@rm -rf $(OBJS)
			@make -C $(LIBFT_DIR) clean
			@make -C $(MLX_DIR) clean
			@printf "🚮 $(NAME)'s object files were removed.\n"


fclean	:	clean
			@rm -rf $(NAME)
			@make -C $(LIBFT_DIR) fclean
			@make -C $(MLX_DIR) clean
			@printf "🚮 $(NAME) was removed.\n"

re	:	fclean all

.PHONY	:	all, clean, fclean, re
