# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejang <ejang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 19:49:35 by ejang             #+#    #+#              #
#    Updated: 2022/08/28 20:03:44 by ejang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3
RM			=	rm -rf

MLX_DIR		=	./mlx/
#MLX_LIB		=	./srcs/libmlx.dylib
MLX_FLAGS	=	-L./mlx -lmlx -framework OpenGL -framework AppKit -lz

LIBFT_DIR 	=  ./libft/
GNL_DIR 	=  ./get_next_line/
M_SRCS_DIR	=  ./srcs/
B_SRCS_DIR	=  ./bonus/

GNL_SRCS	= get_next_line.c get_next_line_utils.c
M_SRCS_SRCS	= main.c init.c parse_main.c parse_map.c raycasting_map.c raycasting.c util.c key_press.c check_map.c parse_color.c parse_main_util.c free.c
B_SRCS_SRCS = check_map_bonus.c init_bonus.c main_bonus.c parse_color_bonus.c parse_main_util_bonus.c raycasting_bonus.c util_bonus.c free_bonus.c key_press_bonus.c mini_map_bonus.c  parse_main_bonus.c parse_map_bonus.c raycasting_map_bonus.c
M_SRCS		=	$(addprefix $(GNL_DIR), $(GNL_SRCS)) $(addprefix $(M_SRCS_DIR), $(M_SRCS_SRCS))
B_SRCS		=	$(addprefix $(GNL_DIR), $(GNL_SRCS)) $(addprefix $(B_SRCS_DIR), $(B_SRCS_SRCS))
M_OBJS		=  $(M_SRCS:.c=.o)
B_OBJS		=  $(B_SRCS:.c=.o)

ifdef WITH_BONUS
	OBJS = $(B_OBJS)
	MLX_LIB = ./bonus/libmlx.dylib
else
	OBJS = $(M_OBJS)
	MLX_LIB	=	./srcs/libmlx.dylib
endif

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				@make -C $(MLX_DIR) all
				@mv	$(MLX_DIR)libmlx.dylib $(MLX_LIB)
				@make -C $(LIBFT_DIR) all
				@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME) $(OBJS)
				@printf "✅ \033[0;32m$(NAME) was created.\033[0m\n"

bonus		:
				@make WITH_BONUS=1 all
	
%.o			:	%.c
				@$(CC) $(CFLAGS) -c $< -o $@

clean		:
				@$(RM) $(M_OBJS) $(B_OBJS)
				@make -C $(MLX_DIR) clean
				@make -C $(LIBFT_DIR) clean
				@printf "🚮 $(NAME)'s object files were removed.\n"

fclean		:	clean
				@$(RM) $(NAME)
				$(RM) ./bonus/libmlx.dylib
				$(RM) ./srcs/libmlx.dylib
				@make -C $(LIBFT_DIR) fclean
				@printf "🚮 $(NAME) was removed.\n"

re			:	fclean all

norm		:
			norminette $(SRCS) inc/cub3d.h

.PHONY		:	all clean fclean re norm bonus