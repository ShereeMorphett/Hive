#include <stdio.h>
#include <unistd.h>


// int is_power_of_2(int n)
// {
// 	if (n & (n -1))
// 	{
// 		return (1);
// 		}
// 		else
// 			return (0);
//}



unsigned char	reverse_bits(unsigned char octet)
{
	return(~octet);
}
void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int main(void)
{
	print_bits('c');
	write(1, "\n", 1);
	print_bits(reverse_bits('c'));



}