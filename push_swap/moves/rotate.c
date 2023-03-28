/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:11:06 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/27 16:11:10 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

/*ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one. */
void	rotate_a(t_stack *stack_data, int print)
{
	int	index;
	int	temp;

	index = 0;
	if (stack_data->size > 1)
	{
		temp = stack_data->a[index];
		while (index != stack_data->size)
		{	
			stack_data->a[index] = stack_data->a[index + 1];
			index++;
		}
		stack_data->a[index - 1] = temp;
		if (print == 1)
			ft_putendl_fd("ra", 1);
	}	
}

/* rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one. */
void	rotate_b(t_stack *stack_data, int print)
{
	int	index;
	int	temp;

	index = 0;
	if (stack_data->stack_b_size > 1)
	{
		temp = stack_data->b[index];
		while (index != stack_data->stack_b_size)
		{	
			stack_data->b[index] = stack_data->b[index + 1];
			index++;
		}
		stack_data->b[index - 1] = temp;
		if (print == 1)
			ft_putendl_fd("rb", 1);
	}	
}

/* rr : ra and rb at the same time */
void	rotate_both(t_stack *stack_data)
{
	rotate_a(stack_data, 0);
	rotate_a(stack_data, 0);
	ft_putendl_fd("rr", 1);
}