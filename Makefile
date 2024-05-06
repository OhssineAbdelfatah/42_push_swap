CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
SRC = push_swap.c 
OBJS = $(SRC:.c=.o) 
 
all : $(NAME) clean

$(NAME): $(OBJS) push_swap.h
	$(CC) $(OBJS) $(CFLAGS)   -o $(NAME)  

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
	
re : fclean all