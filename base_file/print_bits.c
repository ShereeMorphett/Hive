#include <unistd.h>
/* Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010" */

/* 		Mask = 1 = 	0000 0001 
		Octet = 4 = 0000 0100
		count = 7;
		((octet >> count) & mask)
		7: 0000 0000
		6: 0000 0000
		5: 0000 0100
		4: 0000 0000
		3: 0000 0000
		2: 0000 0000
		1: 0000 0000
		0: 0000 0000

*/

void print_bits(unsigned char octet)
{
	int count = 7;
	unsigned char bit;
	unsigned char mask = 0x01;
	while (count >= 0)
	{
		bit = (((octet >> count) & mask) + '0');
		write(1, &bit, 1);
		count--;
	}

}

int main(void)
{
	unsigned char data = 4;

	print_bits(data);

	return (0);
}