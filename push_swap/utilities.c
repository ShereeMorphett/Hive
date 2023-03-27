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
	ft_printf("stack_a size is: %i \n", stack_data->size);
	while (index < stack_data->size)
	{
		ft_putnbr_fd(stack_data->a[index], 1);
		ft_putchar_fd('\n', 1);
		index++;
	}
	index = 0;
	ft_printf("stack_b size is: %i \n", stack_data->stack_b_size);
	while (index < stack_data->stack_b_size)
	{
		ft_putnbr_fd(stack_data->b[index], 1);
		ft_putchar_fd('\n', 1);
		index++;
	}
}

int	check_sorted(t_stack *stack_data, int exit)
{
	int	index;

	index = 0;
	if (stack_data->size != 0)
	{
		while (index + 1 != stack_data->size)
		{
			if (stack_data->a[index] < stack_data->a[index + 1])
				index++;
			else
				return (1);
		}
		if (exit == 1)
			clean_exit(stack_data, 0);
		else
			return (0);
	}
	return (1);
}

void	clean_exit(t_stack *data, int error)
{
	if (error == 1)
		ft_putstr_fd("Error\n", 2);
	if (error == 2)
	{
		exit(EXIT_SUCCESS);
	}
	if (error == 3)
	{	
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_SUCCESS);
	}
	if (error == 0)
	{
		if (data->a)
			free(data->a);
	}
	exit(EXIT_SUCCESS);
}

void	find_range(t_stack *data)
{
	int	index;

	data->max = data->a[0];
	data->min = data->a[0];
	data->max_b = data->b[0];
	data->min_b = data->b[0];
	index = 1;

	while (index < data->size)
	{
		if (data->a[index] > data->max)
			data->max = data->a[index];
		if (data->a[index] < data->min)
			data->min = data->a[index];
		index++;
	}
	index = 1;
		while (index < data->stack_b_size)
	{
		if (data->b[index] > data->max_b)
			data->max_b = data->b[index];
		if (data->b[index] < data->min_b)
			data->min_b = data->b[index];
		index++;
	}
}

void	push_swap(t_stack *stack_data)
{
	check_sorted(stack_data, 1);
	stack_data->b = (int *)malloc(sizeof (int) * stack_data->size);
	stack_data->stack_b_size = 0;
	if (stack_data->size == 2)
		if_two(stack_data);
	else if (stack_data->size == 3)
		if_three(stack_data, 1);
	else if (stack_data->size <= 5)
		if_five(stack_data);
	else
		large_sort(stack_data);
	exit(EXIT_SUCCESS);
}
	