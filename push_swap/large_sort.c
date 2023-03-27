#include "push_swap.h"

void push_back_to_a(t_stack *data)
{	
		 while (data->stack_b_size != 0)
	 {
		if (data->a[0] > data->a[1])
			swap_a(data, 1);
	 	push_a(data);
	
	 }
}

void	large_sort(t_stack *data)
{
	int mid_stack_a;
	int half_stack_a;
	int index;
	int value_hold;

	find_range(data);

	while (data->size != 2)
	{
		find_range(data);
		index = 0;
		mid_stack_a = (data->max + data->min) / 2;
		half_stack_a = (data->size - 1) / 2;

		while (data->a[index] > mid_stack_a)
			index++;
		
		value_hold = data->a[index];
			if (index < half_stack_a)
		{
			while (data->a[0] != value_hold)
				rotate_a(data, 1);
		}
		else if (index > half_stack_a)
		{
			while (data->a[0] != value_hold)
				reverse_a(data, 1);
		}
		if (data->a[0] == data->max)
			rotate_a(data, 1);
		push_b(data);
	}
	if (data->size == 2)
	{
		if (data->a[0] > data->a[1])
			swap_a(data, 1);
	}
	
	ft_printf("\n\n");
	print_stack(data);
	ft_printf("\n\n");
	 push_back_to_a(data);
	
	print_stack(data);
	check_sorted(data, 1);
}