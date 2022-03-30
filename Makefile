PROG	= pipex

SRCS 	= src/pipex.c src/parse.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= src/pipex.c

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