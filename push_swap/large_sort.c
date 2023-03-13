/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:24:50 by smorphet          #+#    #+#             */
/*   Updated: 2023/03/07 12:24:53 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*Find the smallest number in Stack A.-
Move the smallest number found to the top of Stack A.
Push that number to Stack B.
Repeat steps 1–3 until Stack A is empty.
Push everything back to stack A once Stack B has all the numbers from biggest to smallest.
Let's say I have a random list of 100 numbers from 0–99.

Chunk 1 is 0–19

Chunk 2 is 20–39

Chunk 3 is 40–59

Chunk 4 is 60–79

Chunk 5 is 80–99
Step 1: Scan Stack A from the top to confirm if one of the numbers from Chunk 1 exist inside of it. Let's call that number hold_first.
Step 2: Scan Stack A again from the bottom and see if a different number from Chunk 1 exists in that list. I’ll call that number hold_second.
Step 3: Compare how many moves it would take to get hold_first and hold_second to the top.
Step 4: So the correct number is now on to top of Stack A. But there are two things we need to check for before we push the number over to Stack B.
You have to check if the number you’re pushing is either bigger or smaller than all the other numbers in Stack B. Since we’re not just pushing the smallest number one at a time.
We need to make sure we’re not gonna cause an infinite loop by trying to find the perfect spot to insert that number.
In the above example, the quickest way to get the number 10 in the correct spot is to make sure that we get the smallest number (4) and place it on the top of Stack B. After that we can move the number 10 to the top of Stack B.
Regardless of the number at the top of Stack A being bigger or smaller than all the numbers in Stack B. It’s still good to check if you’re placing the number in the correct spot before sending it over.
Step 5: Repeat steps 1–4 until all the numbers in Chunk 1 no longer in Stack A.
Step 6: Repeat steps 1–4 for the rest of the chunks so they are handled in the same way and all of Stack A is inside of Stack B.
Step 7: Now that Stack A is empty, find the biggest number in Stack B, move it to the top, and push it over to Stack A.
Repeat this until Stack B is empty. You can use the logic from Step 3 to determine if you need to use rb or rrb to quickly get the numbers to the top.
*/

int chunking_forward(t_stack *data, int chunk)
{
	int index;
	int found;
	int	first_hold;
	int	second_hold;

	index = 0;
	found = 0;
	while (index <= data->size && found == 0)
	{
		if (data->a[index] <= chunk)
		{
			first_hold = index;
			found = 1;
		}
		else
			index++;
	}
	found = 0;
	index = data->size - 1;
	while (index >= 0 && found == 0)
	{
		if (data->a[index] <= chunk)
		{
			second_hold = index;
			found = 1;
		}
		else
			index--;
	}
	return (index);
}
void if_other(t_stack *data)
{
	chunking_forward(data, 0);
	clean_exit(data, 2);
}
