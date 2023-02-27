/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:45:57 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/20 11:07:48 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$> */

int main (int argc, char *argv[])
{

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int index = 0;
	while(argv[1][index])
	{
		index++;
	}
	index--;
	while(index != 0 && (argv[1][index] == ' ' || argv[1][index] == '\t'))
	{	
		index--;
	}
	int count = 0;
	while(index != 0 && (argv[1][index] != ' ' && argv[1][index] != '\t'))
	{
		count++;
		index--;
	}
	index++;
	count--;
	while (count >= 0)
	{
		write(1, &argv[1][index], 1);
		count--;
		index++;
	}

	write(1, "\n", 1);
	return(0);
}
