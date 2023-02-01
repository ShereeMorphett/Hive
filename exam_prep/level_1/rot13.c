/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:34:58 by smorphet          #+#    #+#             */
/*   Updated: 2023/01/31 11:02:22 by smorphet         ###   ########.fr       */
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


int main (int argc, char *argv[])
{
	int index = 0;

	
	if (argc <=  1)
		write(1, "\n", 1);
	
	while (argv[1][index])
	{
		if (argv[1][index] >= 'a' &&  argv[1][index] <= 'z' )
		{
	   		argv[1][index] = (argv[1][index] - 'a' + 13) % 26 + 'a';
		}
		else if (argv[1][index] >= 'A' &&  argv[1][index] <= 'Z' )
		{
	   		argv[1][index] = (argv[1][index] - 'A' + 13) % 26 + 'A';
		}
		write(1, &argv[1][index] , 1);
		index++;
	}

	return (0);
}
