/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:11:16 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/27 16:11:21 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one */
void	reverse_a(t_stack *stack_data, int print)
{
	int	index;
	int	temp;

	index = stack_data->size - 1;
	if (stack_data->size > 1)
	{
		temp = stack_data->stack_a[stack_data->size - 1];
		while (index != 0)
		{	
			stack_data->stack_a[index] = stack_data->stack_a[index - 1];
			index--;
		}
		stack_data->stack_a[0] = temp;
		if (print == 1)
			ft_putendl_fd("rra", 1);
	}	
}

/* rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
void	reverse_b(t_stack *stack_data, int print)
{
	int	index;
	int	temp;

	index = stack_data->stack_b_size - 1;
	if (stack_data->stack_b_size > 1)
	{
		temp = stack_data->stack_b[stack_data->stack_b_size - 1];
		while (index != 0)
		{	
			stack_data->stack_b[index] = stack_data->stack_b[index - 1];
			index--;
		}
		stack_data->stack_b[0] = temp;
		if (print == 1)
			ft_putendl_fd("rrb", 1);
	}	
}

/* rrr : rra and rrb at the same time.*/
void	reverse_both(t_stack *stack_data)
{
	reverse_a(stack_data, 0);
	reverse_b(stack_data, 0);
	ft_putendl_fd("rrr", 1);
}
