LIBFT = -L./libft/ -lft

FLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = gcc -g -I./header_file/

RM = rm -f

NAME = push_swap

SRC = 	 ./srcs/main.c ./srcs/main_utils.c\
		 ./srcs/parse_info.c ./srcs/sort_algorithm.c ./srcs/sort_algorithm_utils.c\
		 ./srcs/print_operation_list.c ./srcs/find_small_values_and_push_into_b.c\
		 ./srcs/sort_stack_b.c\


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(LIBFT)

clean:
	-@echo "Removing object files..."
	make clean -C ./libft
	$(RM) $(OBJ)

fclean : clean
	-@echo "Removing object files and executive file..."
	make fclean -C ./libft
	$(RM) $(NAME)
