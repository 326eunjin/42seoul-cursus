PROG	= philo

SRCS 	= src/main.c src/error.c src/init.c src/monitor.c src/philo.c src/util.c src/util2.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= src/main.c

HEADER	= -Iincludes

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJS}
					@$(CC) ${OBJS} -o ${PROG}

clean:
					@rm -f ${OBJS}

fclean: 	clean
					@rm -f ${PROG}

re:			fclean all

.PHONY: all clean fclean re 