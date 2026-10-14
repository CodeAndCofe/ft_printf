SRC = ft_printf.c ft_put.c tools.c ft_putstr.c
FLAG = -Wall -Werror -Wextra
CC = cc
OBJ = ${SRC:.c=.o}
NAME = libftprintf.a

all:$(NAME)

$(NAME):$(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o:%.c ft_printf.h
	$(CC) $(FLAG) $< -c -o $@
clean:
	rm -f $(OBJ)
fclean:clean
	rm -f $(NAME)
re:fclean all 