#include "push_swap.h"

static void add_to_array(t_stack *stack_data, char stack)
{
    int index;
	int hold;
 
	if (stack == 'B')
	{
		hold = stack_data->stack_a[0];
		stack_data->stack_b_size++;
		index = stack_data->stack_b_size;
		while(index >= 1)
		{
			index--;
			stack_data->stack_b[index] = stack_data->stack_b[index - 1];
		}
		stack_data->stack_b[0] = hold;
	}
		if (stack == 'A')
	{
		hold = stack_data->stack_b[0];
		stack_data->size++;
		index = stack_data->size;
		while(index >= 1)
		{
			index--;
			stack_data->stack_a[index] = stack_data->stack_a[index - 1];
		}
		stack_data->stack_a[0] = hold;
	}
}
/* pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */

 void push_a(t_stack *stack_data)
{
	int index;
	index = 0;
	printf("\n entered push_a function \n");
	if (stack_data->stack_b_size == 0)
		return;
	else
	{
		add_to_array(stack_data, 'A');
	}
	index = 0;
	while (index < stack_data->stack_b_size)
	{
		stack_data->stack_b[index] = stack_data->stack_b[index + 1];
		index++;
	}
	stack_data->stack_b_size--;
	ft_putendl_fd("pa", 1);
}

/* pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/


void push_b(t_stack *stack_data)
{
	int index;
	index = 0;
	printf("\n entered push_b function \n");
	if (stack_data->size == 0)
		return;
	else
	{
		add_to_array(stack_data, 'B');
	}
	index = 0;
	while (index < stack_data->size)
	{
		stack_data->stack_a[index] = stack_data->stack_a[index + 1];
		index++;
	}
	stack_data->size--;
	ft_putendl_fd("pb", 1);
}
