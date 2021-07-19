NAME = libft.a

CC = gcc -c -g

AR = ar rc

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_isdigit.c ft_bzero.c ft_strlen.c ft_strdup.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
