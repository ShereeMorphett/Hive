
CFLAGS = cc -Wall -Wextra -Werror -o

NAME = push_swap

SRC = 	push_swap.c\

all: $(NAME)
$(NAME):
	@$(MAKE) -C libft/ re
	$(CFLAGS) $(NAME) $(SRC) -L libft/ -lft

clean:
	@$(MAKE) -C libft/ clean

fclean: fclean
	rm -f $(NAME)
	@$(MAKE) -C libft/ fclean

re: fclean all