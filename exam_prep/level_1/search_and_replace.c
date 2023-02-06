/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:05:25 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/05 12:33:05 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
/* Allowed functions: write, exit
  Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $ */

int ft_strlen(char *string)
{
	int index;
	index = 0;

	while (string[index] != '\0')
		index++;
	return (index);

}
int main(int argc, char *argv[])
{
	
	int index = 0;
	if (argc != 4 || ft_strlen(argv[2]) != 1 || ft_strlen(argv[3]) != 1)
	{
		write(1, "\n", 1);
		return (0);
	}

	int len = ft_strlen(argv[1]);

	while (index <= len)
	{
		if (argv[1][index] == *argv[2])
		{
			argv[1][index] = *argv[3]; 
		}
		index++;
	}
	write(1, argv[1], len);
	write(1, "\n", 1);
	
 	return (0);
}
