/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:59:14 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/04 11:59:16 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.*/

/* sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. */
void swap_a(t_stack *stack_data, int print)
{
		printf("\n entered swap_a function \n");
 	int index;
 	int temp;
	index = 0;
	temp = 0;
	if (stack_data->stack_a[index] || stack_data->stack_a[index + 1])
	{
		temp = stack_data->stack_a[index];
		stack_data->stack_a[index] = stack_data->stack_a[index + 1];
		stack_data->stack_a[index + 1] = temp;
	if (print == 1)
		ft_putendl_fd("sa", 1);
	}
}

/* 	sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.*/
void swap_b(t_stack *stack_data, int print)
{
	printf("\n entered swap_b function \n");
 	int index;
 	int temp;
	index = 0;
	temp = 0;
	
	if (stack_data->stack_b[index] || stack_data->stack_b[index + 1])
	{
		temp = stack_data->stack_b[index];
		stack_data->stack_b[index] = stack_data->stack_b[index + 1];
		stack_data->stack_b[index + 1] = temp;
		if (print == 1)
			ft_putendl_fd("sb", 1);
	}
}

/* ss : sa and sb at the same time. */
void swap_both(t_stack *stack_data)
{
	swap_a(stack_data, 0);
	swap_b(stack_data, 0);
	ft_putendl_fd("ss", 1);
}
