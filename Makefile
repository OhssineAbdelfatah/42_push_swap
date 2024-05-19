CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c rules.c utils.c parsing.c sort.c
		
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
FT_PRINTF_DIR =  ./ft_printf
FT_PRINTF =  ./ft_printf/libftprintf.a

RED = \033[0;31m
GREEN = \033[0;32m
END = \033[0m

OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(LIBFT) : 
	@echo "$(GREEN)libft... $(END)"
	@make -C $(LIBFT_DIR)

$(FT_PRINTF) :
	@echo "$(GREEN)ft_printf... $(END) "
	@make -C $(FT_PRINTF_DIR)

$(NAME) : $(OBJ) $(LIBFT) $(FT_PRINTF)   push_swap.h
	@echo "$(GREEN)push_swap...$(END)"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)clean libft $(END)"
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED)clean ft_printf $(END)"
	@make -C $(FT_PRINTF_DIR) clean
	@echo "$(RED)clean push_swap $(END)"
	rm -fr $(OBJ)   

fclean: clean
	rm -fr $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY : clean