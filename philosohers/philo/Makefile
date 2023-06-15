# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 13:37:37 by smorphet          #+#    #+#              #
#    Updated: 2023/06/15 14:25:54 by smorphet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c input_validation.c utilities.c initialization.c routine.c

OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -pthread -g #-g -fsanitize=thread -static-libsan

all: $(NAME)

$(OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	@echo "\033[0;92m* $(NAME) was created *\033[0m"

clean:
	rm -rf $(OBJ)
	@echo "\033[0;91m* $(NAME) .o files were deleted *\033[0m"

fclean: clean
	rm -rf $(NAME)
	@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

re: fclean all

.PHONY: start all clean fclean re

.SILENT:

