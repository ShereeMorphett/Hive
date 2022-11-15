NAME = get_next_line

FLAGS = -Wall -Wextra -Werror 

SRC = main.c, get_next_line.c, get_next_line_utils.c, get_next_line.h

all:	$(NAME)

$(NAME): 
	cc -g $(FLAGS) -D BUFFER_SIZE=4096 main.c get_next_line.c get_next_line_utils.c get_next_line.h

clean:
	/bin/rm -f $(NAME)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
