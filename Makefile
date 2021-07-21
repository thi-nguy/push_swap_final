LIBFT = -L./libft/ -lft

FLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = gcc -g -I./header_file/

RM = rm -f

NAME = push_swap

SRC = 	./srcs/main.c ./srcs/main_utils.c\
		./srcs/parse_info.c ./srcs/move_small_number_up.c\
		./srcs/sort_algorithm.c ./srcs/sort_algorithm_utils.c\
		./srcs/sort_stack_a.c ./srcs/sort_stack_a_utils.c\
		./srcs/sort_stack_b.c ./srcs/sort_stack_b_utils.c\
		./srcs/print_operation_list.c ./srcs/commands.c\
		./srcs/free_memory.c\

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

re: fclean all
