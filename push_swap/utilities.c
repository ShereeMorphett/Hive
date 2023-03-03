/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:49:27 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/04 11:49:29 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_stack(t_stack *stack_data)
{
	int	index;

	index = 0;
	printf("stack_a size is: %i \n", stack_data->size);
	while (index < stack_data->size)
	{
		ft_putnbr_fd(stack_data->a[index], 1);
		ft_putchar_fd('\n', 1);
		index++;
	}
	index = 0;
	printf("stack_b size is: %i \n", stack_data->stack_b_size);
	while (index < stack_data->stack_b_size)
	{
		ft_putnbr_fd(stack_data->b[index], 1);
		ft_putchar_fd('\n', 1);
		index++;
	}
}

static void check_sorted(t_stack *stack_data)
{
	int index;

	index = 0;
	if (stack_data->size != 0)
	{
		while(index + 1 != stack_data->size)
		{
			if (stack_data->a[index] < stack_data->a[index + 1])
				index++;
			else 
				return;
		}
		clean_exit(stack_data, 0);
	}
}

void	clean_exit(t_stack *stack_data, int error)
{
	if (error == 1)
		ft_putendl_fd("Error", 1);
	if (error == 2)
		exit(EXIT_FAILURE);
	if (error == 3)
	{	
		ft_putendl_fd("Error", 1);
		exit(EXIT_FAILURE);
	}
	if (stack_data->a)
		free(stack_data->a);
	if (stack_data->b)
		free(stack_data->b);
	exit(EXIT_SUCCESS);
}

void	push_swap(t_stack *stack_data)
{
	check_sorted(stack_data);
	stack_data->b = (int *)malloc(sizeof (int) * stack_data->size);
	stack_data->stack_b_size = 0;
	if (stack_data->size == 2)
		if_two(stack_data);
	if (stack_data->size == 3)
		if_three(stack_data);
	if (stack_data->size == 5)
		if_five(stack_data);
	print_stack(stack_data);
	exit(EXIT_SUCCESS);
}
