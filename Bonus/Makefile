CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = parsing_01.c parsing_02.c \
rules_01.c rules_02.c \
checker.c utils.c utils_2.c

RED = \033[0;31m
GREEN = \033[0;32m
END = \033[0m

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)
NAME = checker

all: $(NAME)

$(LIBFT) : 
	@echo "$(GREEN)libft... $(END)"
	@make -C $(LIBFT_DIR)

$(NAME) : $(OBJ) $(LIBFT) checker.h
	@echo "$(GREEN)checker...$(END)"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)clean libft $(END)"               
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED)clean checker $(END)"
	rm -fr $(OBJ)   

fclean: clean
	rm -fr $(NAME) $(LIBFT)

re: fclean all

.PHONY : clean