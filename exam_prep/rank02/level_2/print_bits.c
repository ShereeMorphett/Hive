/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:35:47 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/05 12:47:00 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/* Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"   */


void	print_bits(unsigned char octet)
{
	int index = 7;
	int mask = 1;
	char bit;
	while (index >= 0)
	{
		bit = ((octet >> index) & mask) + '0';
		
		write(1, &bit, 1);
		index--;
	}
	
}

int main()
{
	unsigned char octet;
	

	octet = 2;

	print_bits(octet);
	

}
