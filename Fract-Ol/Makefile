NAME	= fractol

SRC		= colours.c event_map.c julia.c main.c mandelbrot.c palette.c utilities.c

OBJ		= colours.o event_map.o julia.o main.o mandelbrot.o palette.o utilities.o

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g


FOUND_OK := $(shell if [ -d ./libft/ ]; then echo "ok"; fi)
ifeq ($(FOUND_OK), ok)
	FT		= ./libft/
else
	FT		= ./../libft/
endif

FT_LIB	= $(addprefix $(FT), libft.a)
FT_INC	= -I $(FT)
FT_LNK	= -L $(FT) -l ft

all: $(FT_LIB) $(NAME)

$(OBJ):
	cc -c $(SRC)

$(FT_LIB):
	@$(MAKE) -C $(FT)

$(NAME): $(FT_LIB) $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) -lmlx -framework OpenGL -framework AppKit -lm -o $(NAME)

clean:
	rm -rf *.o *.gch
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
