/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:08:38 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/06 11:07:59 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
/* Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$> */



int main(int argc, char *argv[])
{
	int index = 0;
	char letter;

	if (argc == 2)
	{
		while (argv[1][index] != '\0')
		{
	
			if (argv[1][index] >= 97 && argv[1][index] <= 122)
			{
				letter = (argv[1][index] + 13 - 'a') % 26 + 'a';
				write(1, &letter, 1);
				index++;
			}
			else if (argv[1][index] >= 65 && argv[1][index] <= 90)
			{
				letter = (argv[1][index] + 13 - 'A') % 26 + 'A';
				write(1, &letter, 1);
				index++;
			}
			else
			{
				write(1, &argv[1][index++], 1);
			}
		}
	}
		write(1, "\n", 1);		
		return (0);
}
