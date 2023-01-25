# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smorphet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 08:51:56 by smorphet          #+#    #+#              #
#    Updated: 2023/01/25 08:51:58 by smorphet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S	= server
NAME_C	= client
SRC_C	= client.c
SRC_S	= server.c
OBJ_C	= client.o
OBJ_S	= server.o

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

all: $(FT_LIB) $(NAME_S) $(NAME_C)

$(OBJ_S):
	cc -c $(CFLAGS)  $(SRC_S)

$(OBJ_C):
	cc -c $(CFLAGS) $(SRC_C)

$(FT_LIB):
	@$(MAKE) -C $(FT)

$(NAME_S): $(FT_LIB) $(OBJ_S)
	$(CC) $(OBJ_S) $(FT_LNK) -o $(NAME_S)

$(NAME_C): $(FT_LIB) $(OBJ_C)
	$(CC) $(OBJ_C) $(FT_LNK) -o $(NAME_C)

clean:
	rm -rf *.o *.gch
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME) $(NAME_S) $(NAMEBC) $(NAMEBS)
	rm -rf $(NAME_C)
	make -C $(FT) fclean

re: fclean all

.PHONY:		start all clean fclean re bonus norm
