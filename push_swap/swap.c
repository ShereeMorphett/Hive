/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:10:53 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/27 16:10:59 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* sa (swap a): Swap the first 2 elements at the top of stack a. 
Do nothing if there is only one or no elements. */
void	swap_a(t_stack *stack_data, int print)
{
	int	index;
	int	temp;

	index = 0;
	temp = 0;
	if (stack_data->a[index] || stack_data->a[index + 1])
	{
		temp = stack_data->a[index];
		stack_data->a[index] = stack_data->a[index + 1];
		stack_data->a[index + 1] = temp;
		if (print == 1)
			ft_putendl_fd("sa", 1);
	}
}

/* 	sb (swap b): Swap the first 2 elements at the top of stack b. 
Do nothing if there is only one or no elements.*/
void	swap_b(t_stack *stack_data, int print)
{
	int	index;
	int	temp;

	index = 0;
	temp = 0;
	if (stack_data->b[index] || stack_data->b[index + 1])
	{
		temp = stack_data->b[index];
		stack_data->b[index] = stack_data->b[index + 1];
		stack_data->b[index + 1] = temp;
		if (print == 1)
			ft_putendl_fd("sb", 1);
	}
}

/* ss : sa and sb at the same time. */
void	swap_both(t_stack *stack_data)
{
	swap_a(stack_data, 0);
	swap_b(stack_data, 0);
	ft_putendl_fd("ss", 1);
}
