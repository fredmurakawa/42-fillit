NAME = fillit

SRC =	buf.c\
	   	ft_s_point.c\
		grid.c\
		solve.c\
		main.c\
		tet.c\
		ft_putchar.c\
		tet_error.c\
		tet_error2.c\
		tet_read.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@gcc -Wall -Werror -Wextra $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all clean
