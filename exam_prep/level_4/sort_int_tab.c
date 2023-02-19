
#include <stdio.h>

/* Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent. */

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int index = 0;
	int hold;
	int sorted = 0;
	while (sorted != 1)
	{
		if (tab[index] > tab[index + 1] && index + 1 != size)
		{	
			hold = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = hold;
			index++;
		} 
		index = 0;
		while (tab[index] <= tab[index + 1])
		{
			index++;
			if (index == size)
			{
				sorted = 1;
				break;
			}
		}
	}

}


int main()
{
	int array[5] = {-15, -15, 3, 2, 1};

//	int index = 0;

	sort_int_tab(array, 5);

	// while (index < 5 )
	// {
	// 	printf("%i\n", array[index]);
	// 	index++;
	// }

	return(0);
}