/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:52:59 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/07 10:26:03 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$ */

int strlen_cap(char argv)
{

	int count = 0;
	int index = 0;

	while (argv[1][index])
	{
	
		if (argv[1][index] <= 65 && argv[1][index] >= 90)
			count++;
		count++;
		index++;
	}
 	return (count);
}

void ft_putstring(char *string)
{
	int index = 0;
	while (string[index] != '\0')
	{
		write(1, &string[index], 1);
		index++;
	}

}

int main( int argc, char *argv[])
{
	int count = strlen_cap(argv[1]);
	char *string = (char) malloc(sizeof(char) * count);
	int index = 0;
	int str_index = 0;	

	while (argv[1][index] != '\0')
	{

		if (argv[1][index] <= 65 && argv[1][index] >= 90)
		{
			string[str_index++] = "_";	
		}
		string(str_index) = argv[1][index];
	}
	ft_putstring(&string);

	return (0);
}
