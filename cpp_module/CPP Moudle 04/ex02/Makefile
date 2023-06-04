PROG	= Animal

SRC 	= main.cpp Animal.cpp WrongAnimal.cpp Dog.cpp Cat.cpp WrongCat.cpp Brain.cpp AAnimal.cpp
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
