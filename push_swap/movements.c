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
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.*/

/* sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. */
void swap_a(t_stack *stack_data)
{
	printf("\n entered swap function \n");
 	int index;
 	int temp;

	index = 0;
	temp = 0;
	if (stack_data->stack_a[index] || stack_data->stack_a[index + 1])
	{
		temp = stack_data->stack_a[index];
		stack_data->stack_a[index] = stack_data->stack_a[index + 1];
		stack_data->stack_a[index + 1] = temp;
	}
	ft_putendl_fd("sa", 1);
}

/*sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.*/
void swap_b(t_stack *stack_data)
{
	printf("\n entered swap function \n");
 	int index;
 	int temp;

	index = 0;
	temp = 0;
	
	if (stack_data->stack_b[index] || stack_data->stack_b[index + 1])
	{
		temp = stack_data->stack_b[index];
		stack_data->stack_b[index] = stack_data->stack_b[index + 1];
		stack_data->stack_b[index + 1] = temp;
	}
	ft_putendl_fd("sb", 1);
}

/* ss : sa and sb at the same time. */
void swap_both(t_stack *stack_data)
{
	int index;
 	int temp;

	index = 0;
	temp = 0;
	
	if (stack_data->stack_a[index] || stack_data->stack_a[index + 1])
	{
		temp = stack_data->stack_a[index];
		stack_data->stack_a[index] = stack_data->stack_a[index + 1];
		stack_data->stack_a[index + 1] = temp;
	}
	index = 0;
	temp = 0;
	if (stack_data->stack_b[index] || stack_data->stack_b[index + 1])
	{
		temp = stack_data->stack_b[index];
		stack_data->stack_b[index] = stack_data->stack_b[index + 1];
		stack_data->stack_b[index + 1] = temp;
	}
	ft_putendl_fd("ss",1);
}



/* pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */
// void push_a(t_stack *stack_data)
// {
// 	int index;
// 	index = 0;
// 	printf("\n entered push_a function \n");
// 	if (stack_data->stack_b[0])
// 	{
// 		stack_data->stack_a[0] = stack_data->stack_b[0];
// 	}
// 	while (index < stack_data->stack_b_size)
// 	{	
// 		stack_data->stack_b[index] = stack_data->stack_b[index + 1];
// 		index++;
// 	}
// 	stack_data->size++;
// 	stack_data->stack_b_size--;
// 	ft_putendl_fd("pa", 1);
// }




/* pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/




// void push_b(t_stack *stack_data)
// {
// 	int index;
// 	int temp;

// 	index = 0;
// 	printf("\n entered push_a function \n");
// 	if (stack_data->stack_a[0] && !stack_data->stack_b[0])
// 	{
// 		stack_data->stack_b[0] = stack_data->stack_a[0];
// 	}
// 	else if (stack_data->stack_a[0] && stack_data->stack_b[0])
// 	{
// 		temp = stack_data->stack_b[0];
// 		stack_data->stack_b[0] = stack_data->stack_a[0];
// 		// while (index <= stack_data->stack_b_size)
// 		// {
// 		// 	//temp = stack_data->stack_b[index];
// 		// 	stack_data->stack_b[index] = stack_data->stack_a[index + 1];
// 		// 	index++;
// 		// }
// 	}
// 	while (index < stack_data->size)
// 	{	
// 		stack_data->stack_a[index] = stack_data->stack_a[index + 1];
// 		index++;
// 	}
// 	stack_data->size--;
// 	stack_data->stack_b_size++;
// 	ft_putendl_fd("pb", 1);
// }
