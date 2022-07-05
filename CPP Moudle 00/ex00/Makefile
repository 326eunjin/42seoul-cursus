PROG	= megaphone

SRC 	= megaphone.cpp
OBJ 	= ${SRC:.cpp=.o}

CC 		= c++
CFLAGS 	= -Wall -Werror -Wextra -std=c++98

%.o: %.cpp
		@$(CC) ${CFLAGS} -c $< -o $(<:.cpp=.o)

all: 	${PROG}

${PROG}: ${OBJ}
		@$(CC) ${OBJ} -o ${PROG}

clean:
		@rm -f ${OBJ}

fclean: clean
		@rm -f ${PROG}

re:		fclean all

.PHONY: all clean fclean re 