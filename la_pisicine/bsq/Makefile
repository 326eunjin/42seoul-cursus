CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs
HEAD_DIR = ./includes

TARGET = bsq 

SOURCES := $(SRC_DIR)/ft_function.c $(SRC_DIR)/ft_memory_free.c $(SRC_DIR)/ft_read_file.c $(SRC_DIR)/ft_solve.c $(SRC_DIR)/main.c $(SRC_DIR)/ft_is_valid.c $(SRC_DIR)/ft_print_map.c $(SRC_DIR)/ft_read_stdin.c $(SRC_DIR)/ft_split.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CC) $(CFLAGS) $^ -o $@ -I $(HEAD_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEAD_DIR)

.PHONY: clean
clean:
	rm -f $(OBJECTS)

.PHONY: fclean
fclean:	
	make clean
	rm -f $(TARGET)

.PHONY: re
re: 
	make fclean 
	make all
