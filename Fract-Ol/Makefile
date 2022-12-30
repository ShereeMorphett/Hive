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
	MLX		= ./miniLibX/
	MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
endif

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft -l pthread

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	cc -c $(SRC)

$(OBJDIR)/%.o:%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

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
