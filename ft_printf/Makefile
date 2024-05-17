CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC =	ft_printf.c \
		printchar.c \
		printnbr.c \
		printstr.c \
		printhexa.c

OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY : clean

