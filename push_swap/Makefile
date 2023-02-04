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
SRC	= push_swap.c utilities.c movements.c
OBJ	= push_swap.o utilities.o movements.o

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

all: $(FT_LIB) $(NAME) $(NAME)

$(OBJ):
	cc -c $(CFLAGS)  $(SRC)

$(FT_LIB):
	@$(MAKE) -C $(FT)

$(NAME): $(FT_LIB) $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) -o $(NAME)

clean:
	rm -rf *.o *.gch
	make -C $(FT) clean

fclean: clean
	rm -rf  $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY:		start all clean fclean re bonus norm
