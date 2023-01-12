NAME	= fractol

SRC		= *.c

OBJ		= *.o

# compiler
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

all: obj $(FT_LIB) $(NAME)

obj:
	cc -c $(SRC)

$(OBJDIR)/%.o:%.c
	$(CC) $(CFLAGS) $(FT_INC) -o $@ -c $<

$(FT_LIB):
	@$(MAKE) -C $(FT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) -lmlx -framework OpenGL -framework AppKit -lm -o $(NAME)

clean:
	rm -rf *.o *.gch
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
