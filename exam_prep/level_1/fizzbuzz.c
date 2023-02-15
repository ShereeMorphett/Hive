/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:37:11 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/07 09:50:58 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
/* Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$> */

void	ft_write_number(int number)
{
	char	str[10] = "0123456789";

	if (number > 9)
		ft_write_number(number / 10);
	write (1, &str[number % 10], 1);
}

int main(void)
{

	int count = 1;

	while (count <= 100)
	{
		if (count % 15 == 0)	
			write(1, "fizzbuzz", 8);
		else if (count % 5 == 0)
			write(1, "buzz", 4);
		else if (count % 3 == 0)
			write(1, "fizz", 4);
		else
			ft_write_number(count);
		write(1, "\n", 1);
		count++;
	}

	return (0);
	
	}

