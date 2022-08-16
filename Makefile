NAME		=	test_cub

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address
RM			=	rm -rf

MLX_DIR		=	./mlx/
MLX_LIB		=	libmlx.dylib
MLX_FLAGS	=	-L./mlx -lmlx -framework OpenGL -framework AppKit -lz

SRCS		=	./srcs/test.c
OBJS		=	./srcs/test.o

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			make -C $(MLX_DIR) all
			$(CC) $(CFLAGS)	$(MLX_FLAGS) -o $(NAME) $(OBJS)

%.o			:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean		:
			$(RM) $(OBJS)
			make -C $(MLX_DIR) clean

fclean		:	clean
			$(RM) $(NAME)
			$(RM) $(MLX_LIB)

re			:	fclean all

norm		:
			norminette $(SRCS) so_long.h

.PHONY		:	all clean fclean re norm