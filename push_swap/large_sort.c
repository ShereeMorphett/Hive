#include "push_swap.h"

void push_back_to_a(t_stack *data)
{
	int index;
	int half_stack_b;

	while (data->stack_b_size != 0)
	{
		find_range(data);
		half_stack_b = (data->stack_b_size - 1) / 2;
		index = 0;
		while (data->b[index] != data->max_b)
			index++;
		if (index <= half_stack_b)
		{
			while (data->b[0] != data->max_b)	
				rotate_b(data, 1);
		}
		else if (index > half_stack_b)
		{
			while (data->b[0] != data->max_b)	
				reverse_b(data, 1);
		}
		push_a(data);
	 	if (data->a[0] > data->a[1])
	 		swap_a(data, 1);
	 }
}

void	large_sort(t_stack *data)
{

	int half_stack_a;
	int mid_stack_a;
	int index;
	int value_hold;

	while (data->size > 1)
	{	
		find_range(data);
		half_stack_a = (data->size - 1) / 2;
		mid_stack_a =  (data->max + data->min) / 2;
		index = 0;
		value_hold = 0;
		while (data->a[index] > mid_stack_a && index < data->size - 1)
			index++; 
		value_hold = data->a[index];
		if (index <= half_stack_a)
			{
				while (data->a[0] != value_hold)
					rotate_a(data, 1);
			}
			else if (index > half_stack_a)
			{
				while (data->a[0] != value_hold)
					reverse_a(data, 1);
			}
			push_b(data);
	}
	
	
	push_back_to_a(data);
	//print_stack(data);
	check_sorted(data, 1);
}