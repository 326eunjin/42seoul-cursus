NAME = libftprintf.a

CC = gcc

INCLUDE = -I ./include

CFLAGS = -Wall -Werror -Wextra $(INCLUDE) 

SRC = ./src/

MAIN = $(addprefix $(SRC), \
	ft_printf.c ft_print_hex.c ft_print_nbr.c \
	ft_print_pointer.c ft_print_str.c ft_print_unnbr.c)

OBJ = $(MAIN:%.c=%.o)

$(NAME): $(OBJ)
	make all -C ./libft
	cp ./libft/libft.a libftprintf.a
	ar -rcs $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf ./a.out
	make clean -C ./libft


fclean:	clean
	rm -rf $(NAME)
	make fclean -C ./libft

re:	fclean all