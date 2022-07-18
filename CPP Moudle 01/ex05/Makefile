PROG	= Harl

SRC 	= main.cpp Harl.cpp 
OBJ 	= ${SRC:.cpp=.o}

CC 		= c++
CFLAGS 	= -Wall -Werror -Wextra -std=c++98

all: 	${PROG}

${PROG}: ${OBJ}
		@$(CC) ${CFLAGS} ${OBJ} -o ${PROG}

%.o: %.cpp
		@$(CC) ${CFLAGS} -c $< -o $@

clean:
		@rm -f ${OBJ}

fclean: clean
		@rm -f ${PROG}

re:		fclean all

.PHONY: all clean fclean re PROG	= ref
