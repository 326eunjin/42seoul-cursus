PROG	= push_swap

SRCS 	= src/arg_check.c src/deque_back.c src/deque_front.c src/error_free.c src/instruction.c src/main.c src/push_swap.c src/sort_little.c src/sort.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= src/push_swap.c

HEADER	= -Iincludes

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJS}
					@make re -C ./libft
					@$(CC) ${OBJS} -Llibft -lft -o ${PROG}

clean:
					@make clean -C ./libft
					@rm -f ${OBJS}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)
					@rm -f ${PROG}

re:			fclean all

.PHONY: all clean fclean re 