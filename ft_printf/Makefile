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

SRC = ft_atoi.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
	ft_strchr.c ft_striteri.c ft_strlen.c ft_strnstr.c \
	
OBJ = ft_atoi.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o\
	ft_strchr.o ft_striteri.o ft_strlen.o ft_strnstr.o \
	

all:	$(NAME)

$(NAME): 
	cc -c $(SRC)
	ar rc $(NAME) $(OBJ)
clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
