# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smorphet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 10:30:50 by smorphet          #+#    #+#              #
#    Updated: 2023/02/01 10:30:55 by smorphet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC	= push_swap.c utilities.c moves/swap.c moves/push.c moves/rotate.c moves/reverse.c sorting.c input_validation.c op_utilities.c large_sort.c

OBJ	= push_swap.o utilities.o swap.o push.o rotate.o reverse.o sorting.o input_validation.o op_utilities.o large_sort.o

CC		= cc
FLAGS	= -Wall -Wextra -Werror -pedantic

FOUND_OK := $(shell if [ -d ./libft/ ]; then echo "ok"; fi)
ifeq ($(FOUND_OK), ok)
	FT		= ./libft/
else
	FT		= ./../libft/
endif

FT_LIB	= $(addprefix $(FT), libft.a)
FT_INC	= -I $(FT)
FT_LNK	= -L $(FT) -l ft

all: $(FT_LIB) $(NAME) $(NAME)

$(OBJ):
	cc -c $(FLAGS) $(SRC)

$(FT_LIB):
	@$(MAKE) -C $(FT)

$(NAME): $(FT_LIB) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(FT_LNK) -o $(NAME)
	@echo "\033[0;92m* $(NAME) was created *\033[0m"

clean:
	rm -rf push_swap.o utilities.o swap.o push.o rotate.o reverse.o sorting.o input_validation.o op_utilities.o large_sort.o
	make -C $(FT) clean
	@echo "\033[0;91m* $(NAME) .o files were deleted *\033[0m"

fclean: clean
	rm -rf  $(NAME)
	make -C $(FT) fclean
	@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

re: fclean all

.PHONY:		start all clean fclean re bonus norm
.SILENT:
