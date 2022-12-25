//http://www.lunderberg.com/2015/08/24/cpp-makefile-multiple-libraries/
NAME = push_swap

CFILES = push_swap.c

OBJECTS = $(CFILES:.c=.o)

LIB_PATH = libft/

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: libft_make $(NAME)

libft_make:
	make -C $(LIB_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB_PATH)libft.a -o $(NAME)

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME)

re: fclean all

call: all clean
	make -C $(LIB_PATH) fclean