/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:35:03 by smorphet          #+#    #+#             */
/*   Updated: 2023/03/01 12:35:05 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	if_two(t_stack *data)
{
	if (data->size == 2)
	{
		if (data->a[0] > data->a[1])
			swap_a(data, 1);
	}
}

int	if_three(t_stack *data, int exit)
{
	while (data->a)
	{
		if ((data->a[0] > data->a[1] && data->a[1] < data->a[2]) && data->a[0] > data->a[2])
			rotate_a(data, 1);
		else if (data->a[0] > data->a[1] && data->a[1] > data->a[2])
		{
			swap_a(data, 1);
			if (check_sorted(data, exit))
				reverse_a(data, 1);
		}
		else if (data->a[0] < data->a[1] && data->a[1] > data->a[2])
		{
			reverse_a(data, 1);
			if (check_sorted(data, exit))
				swap_a(data, 1);
		}
		else if (data->a[0] > data->a[1] && data->a[1] < data->a[2])
			swap_a(data, exit);
		
		if (!check_sorted(data, exit))
			return (0);
	}
	return (0);
}

int check_a_sorted(t_stack *data)
{
	int index;

	index = 0;
	if (data->size >= 2)
	{
		while (data->a[index] < data->a[index + 1])
			index++;
		
		if (index < data->size)
			return (1);
		else
			return (0);
	}
	else
		return (1);
}

int check(t_stack *data, int max_size)
{
	if (data->size == max_size)
	{
		ft_printf("\n %i \n", check_sorted(data, 0));
		return (check_sorted(data, 0));
		
	}
	else
		return (1);
}

void push_back(t_stack *data)
{
	while (data->stack_b_size != 0)
	{
		if (data->a[0] > data->a[1])
			swap_a(data, 1);
		push_a(data);
		if (data->a[0] > data->a[1])
			swap_a(data, 1);
	}
}
 void if_five(t_stack *data)
{
	int max_size;
	
	max_size = data->size;
	find_range(data);
	while (check(data, max_size) != 0)
	{
		while (data->size > 2)
		{
			if (check_a_sorted(data) == 0)
				break;
			if (data->a[data->size - 1] == data->min)
				reverse_a(data, 1);
			if (data->a[0] == data->max)
				rotate_a(data, 1);
			else if (data->a[0] < data->a[1])
				push_b(data);
			else if (data->a[0] > data->a[1])
			{
				swap_a(data, 1);
				push_b(data);
			}
			if (data->stack_b_size == 2)
			{
				if (data->b[0] < data->b[1])
					swap_b(data, 1);
			}
			if (data->stack_b_size > 2)
			{
				if (data->a[0] > data->a[1] && data->b[0] < data->b[1])
					swap_both(data);
				if (data->b[0] == data->min)
					rotate_b(data, 1);
				if (data->b[0] < data->b[1])
					swap_b(data, 1);
			}
		}
		while (data->size != max_size)
		{
			push_back(data);
		}
		if (data->a[0] != data->min && data->a[1] == data->min)
			swap_a(data, 1);

	}
	check_sorted(data, 1);
}