PROG	= fractol

SRCS 	= src/draw.c src/error.c src/event.c src/ft_atod.c src/init_fractol.c \
src/julia_mandelbrot.c src/main.c 
OBJS 	= ${SRCS:.c=.o}
MAIN	= src/main.c

HEADER	= -Iincludes

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJS}
					@make re -C ./libft
					@$(CC) ${OBJS} -Llibft -lft -lmlx -framework OpenGL -framework AppKit -o ${PROG}

clean:
					@make clean -C ./libft
					@rm -f ${OBJS}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)
					@rm -f ${PROG}

re:			fclean all

.PHONY: all clean fclean re 