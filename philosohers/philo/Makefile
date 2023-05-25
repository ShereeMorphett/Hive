# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smorphet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 13:37:37 by smorphet          #+#    #+#              #
#    Updated: 2023/05/25 13:37:39 by smorphet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC	= philosophers.c

OBJ	= philosophers.o

CC		= cc
FLAGS	= -Wall -Wextra -Werror -g

all: $(NAME)

$(OBJ):
	cc -c $(FLAGS) $(SRC)


$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) -o $(NAME)
	@echo "\033[0;92m* $(NAME) was created *\033[0m"

clean:
	rm -rf *.o *.gch
	@echo "\033[0;91m* $(NAME) .o files were deleted *\033[0m"

fclean: clean
	rm -rf  $(NAME)
	@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

re: fclean all

.PHONY:		start all clean fclean re bonus norm
.SILENT:
