NAME = push_swap.a

FLAGS = -Wall -Wextra -Werror

SRCS= push_swap.c

OBJ= push_swap.o

LIBFT= $(MAKE) -C ../libft
		cp libft.a

all:	$(NAME)

$(NAME): 
	cc -c $(SRC) $(LIBFT)
	ar rc $(NAME) $(OBJ)
clean:
	/bin/rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
