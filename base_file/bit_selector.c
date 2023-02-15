#include <stdio.h>
/*
	[n:m]
	[0:3] = 0x000D
	[4:7] = 0x000C
	[8:11] = 0x000B
	[12:15] = 0x000A
*/


int main(void)
{

	unsigned n = 8;
	unsigned m = 11;
	unsigned data = 0xABCD;
	unsigned w= m - n + 1;
	unsigned result = data >> n;
	unsigned mask = (1 << w) - 1; 


	printf("data =  0x%04X \n", data);
	printf("result =  0x%04X \n", result);

	result = data >> n & mask;

	printf("result =  0x%04X \n", result);



}