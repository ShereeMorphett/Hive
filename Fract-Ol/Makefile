NAME	= fractol
OS		= $(shell uname)
SRC		= *.c

OBJ		= *.o

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g


# mlx library
ifeq ($(OS), Linux)
	MLX		= ./miniLibX_X11/
	MLX_LNK	= -L $(MLX) -l mlx -lXext -lX11
else
	FOUND_OK := $(shell if [ -d ./miniLibX/ ]; then echo "ok"; fi)
	ifeq ($(FOUND_OK), ok)
		MLX		= ./miniLibX/
	else
		MLX		= ./../miniLibX/
	endif
	MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
endif

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX), libmlx.a)

MLX_LIB = $(addprefix $(MLX), libmlx_Darwin.a)


# ft library
FOUND_OK := $(shell if [ -d ./libft/ ]; then echo "ok"; fi)
ifeq ($(FOUND_OK), ok)
	FT		= ./libft/
else
	FT		= ./../libft/
endif

FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I $(FT)
FT_LNK	= -L $(FT) -l ft -l pthread

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	cc -c $(SRC) $(MLX_INC)

$(OBJDIR)/%.o:%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -o $@ -c $<

$(FT_LIB):
	@$(MAKE) -C $(FT)

$(MLX_LIB):
	@$(MAKE) -C $(MLX) 

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf *.o *.gch
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
