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
/*
Chunk 1 is 0–19

Chunk 2 is 20–39

Chunk 3 is 40–59

Chunk 4 is 60–79

Chunk 5 is 80–99
Step 4: 
You have to check if the number you’re pushing is either bigger or smaller than all the other numbers in Stack B. Since we’re not just pushing the smallest number one at a time.
We need to make sure we’re not gonna cause an infinite loop by trying to find the perfect spot to insert that number.
In the above example, the quickest way to get the number 10 in the correct spot is to make sure that we get the smallest number (4) and place it on the top of Stack B. After that we can move the number 10 to the top of Stack B.
Regardless of the number at the top of Stack A being bigger or smaller than all the numbers in Stack B. It’s still good to check if you’re placing the number in the correct spot before sending it over.
Step 7: Now that Stack A is empty, find the biggest number in Stack B, move it to the top, and push it over to Stack A.
Repeat this until Stack B is empty. You can use the logic from Step 3 to determine if you need to use rb or rrb to quickly get the numbers to the top.
*/

static void moving_to_top(t_stack *data)
{
	int length;

	if (data->found != 0)
	{
		length = data->size - data->second_hold - 1;
		if (length < data->first_hold)
		{
			while(length >= 0)
			{
				reverse_a(data, 1);
				length--;
			}
		}
		else 
		{
			length = data->first_hold - 1;	
			while(length >= 0)
			{
				rotate_a(data, 1);
				length--;
			}
		}
		sorting_b(data);
	}
}

void sorting_b(t_stack *data)
{
	push_b(data);
	if(data->stack_b_size > 1)
	{
		if (data->b[0] < data->b[1])
			swap_b(data, 1);
	}
}

int b_max(t_stack *data)
{
	int index;
	int max_index;

	index = 0;
	max_index = 1;

	while (index < data->stack_b_size)
	{
		if (data->b[index] > data->b[max_index])
		{
			max_index = index;
			index++;
		}
		else
			index++;
	}
	return (max_index);
}

void if_other(t_stack *data)
{	
	int chunk;
	int bmax;
	int length;

	find_range(data);
	chunk = data->min + 20;
	while (data->size != 0)
	{
		chunking_forward(data, chunk);
		chunking_back(data, chunk);
		moving_to_top(data);
		if (data->size != 0 && data->found == 0)
		{
			chunk += 50;
			if (chunk > data->max)
				chunk = data->max;
		}
	}

	while (data->stack_b_size != 0)
	{
		bmax = b_max(data);
		length = data->size - bmax - 1;
		if (length < data->stack_b_size / 2)
		{
			while(length >= 0)
			{
				reverse_b(data, 1);
				length--;
			}
		}
		else 
		{	
			while(length >= 0)
			{
				rotate_b(data, 1);
				length--;
			}
		}
		push_a(data);
	}
	print_stack(data);
	clean_exit(data, 2);
}
