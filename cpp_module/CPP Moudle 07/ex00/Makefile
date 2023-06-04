PROG	= Whatever
SRC 	= main.cpp 
OBJ 	= ${SRC:.cpp=.o}

CXX 		= c++
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98

all: 	${PROG}

${PROG}: ${OBJ}
		@$(CXX) ${CXXFLAGS} ${OBJ} -o ${PROG}

%.o: %.cpp
		@$(CXX) ${CXXFLAGS} -c $< -o $@

clean:
		@rm -f ${OBJ}

fclean: clean
		@rm -f ${PROG}

re:		fclean all

.PHONY: all clean fclean
