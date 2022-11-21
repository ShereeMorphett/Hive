# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#                                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smorphet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:46:20 by smorphet          #+#    #+#              #
#    Updated: 2022/10/24 16:48:27 by smorphet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = utilities.c ft_printf.c ft_printf.h

	
OBJ = utilities.o ft_printf.o
	

all:	$(NAME)

$(NAME): 
	cc -c $(SRC)
	ar rc $(NAME) $(OBJ)
clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
