# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejang <ejang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 16:26:52 by ejang             #+#    #+#              #
#    Updated: 2022/08/23 16:31:48 by ejang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g3
RM			=	rm -rf

MLX_DIR		=	./mlx/
MLX_LIB		=	./srcs/libmlx.dylib
MLX_FLAGS	=	-L./mlx -lmlx -framework OpenGL -framework AppKit -lz

LIBFT_DIR 	=  ./libft/
GNL_DIR 	=  ./get_next_line/
SRCS_DIR	=  ./srcs/

GNL_SRCS	= get_next_line.c get_next_line_utils.c
SRCS_SRCS	= main.c init.c parse_main.c parse_map.c raycasting_map.c raycasting_util.c raycasting.c util.c key_press.c check_map.c
SRCS		=	$(addprefix $(GNL_DIR), $(GNL_SRCS)) $(addprefix $(SRCS_DIR), $(SRCS_SRCS))
OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				@make -C $(MLX_DIR) all
				@make -C $(LIBFT_DIR) all
				@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME) $(OBJS)
				@printf "✅ \033[0;32m$(NAME) was created.\033[0m\n"

%.o			:	%.c
				@$(CC) $(CFLAGS) -c $< -o $@

clean		:
				@$(RM) $(OBJS)
				@make -C $(MLX_DIR) clean
				@make -C $(LIBFT_DIR) clean
				@printf "🚮 $(NAME)'s object files were removed.\n"

fclean		:	clean
				@$(RM) $(NAME)
				@$(RM) $(MLX_LIB)
				@make -C $(LIBFT_DIR) fclean
				@printf "🚮 $(NAME) was removed.\n"

re			:	fclean all

norm		:
			norminette $(SRCS) inc/cub3d.h

.PHONY		:	all clean fclean re norm