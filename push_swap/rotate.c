#include "push_swap.h"

/*ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one. */
void rotate_a(t_stack *stack_data, int print)
{
	int index;
	int temp;
	index = 0;
	printf("\n entered rotate_a function \n");
	if (stack_data->size > 1)
	{
		temp = stack_data->stack_a[index];
		while(index != stack_data->size)
		{	
			stack_data->stack_a[index] = stack_data->stack_a[index + 1];
		 	index++;
		}
		stack_data->stack_a[index - 1] = temp;
		if (print == 1)
			ft_putendl_fd("ra", 1);
	}	
}

/* rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one. */
void rotate_b(t_stack *stack_data, int print)
{
	int index;
	int temp;
	index = 0;
	printf("\n entered rotate_b function \n");
	
	if (stack_data->stack_b_size > 1)
	{
		temp = stack_data->stack_b[index];
		while(index != stack_data->size)
		{	
			stack_data->stack_b[index] = stack_data->stack_b[index + 1];
		 	index++;
		}
		stack_data->stack_b[index - 1] = temp;
		if (print == 1)
			ft_putendl_fd("ra", 1);
	}	
}

/* rr : ra and rb at the same time */
void rotate_both(t_stack *stack_data)
{
		rotate_a(stack_data, 0);
		rotate_a(stack_data, 0);
		ft_putendl_fd("rr", 1);
}