/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:50:31 by smorphet          #+#    #+#             */
/*   Updated: 2023/03/28 17:50:34 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_back_to_a(t_stack *data)
{
	int	index;
	int	half_stack_b;

	while (data->stack_b_size != 0)
	{
		find_range(data);
		half_stack_b = (data->stack_b_size - 1) / 2;
		index = 0;
		while (data->b[index] != data->max_b)
			index++;
		if (index <= half_stack_b)
		{
			while (data->b[0] != data->max_b)
				rotate_b(data, 1);
		}
		else if (index > half_stack_b)
		{
			while (data->b[0] != data->max_b)
				reverse_b(data, 1);
		}
		push_a(data);
		if (data->a[0] > data->a[1])
			swap_a(data, 1);
	}
}

int	recursive_mean(t_stack *data, long long sum)
{
	int	index;
	int	mean;
	int	count;

	mean = sum;
	sum = 0;
	count = 0;
	index = 0;
	while (index < data->size)
	{
		if (data->a[index] < mean)
		{
			sum = sum + (long long) data->a[index];
			count++;
		}
		index++;
	}
	sum = sum / count;
	if (count >= 50)
	{
		sum = recursive_mean(data, sum);
	}
	return (sum);
}

int	get_mean(t_stack *data)
{
	long long	sum;
	int			index;

	index = 0;
	sum = 0;
	while (index < data->size)
	{
		sum = sum + (long long) data->a[index];
		index++;
	}
	sum = sum / data->size;
	if (data->size < 50)
		return (sum);
	else
		sum = recursive_mean(data, sum);
	return (sum);
}

void	position_stack_a(t_stack *data, int half_stack_a, int value_hold, int i)
{
	if (i <= half_stack_a)
	{
		while (data->a[0] != value_hold)
			rotate_a(data, 1);
	}
	else if (i > half_stack_a)
	{
		while (data->a[0] != value_hold)
			reverse_a(data, 1);
	}
}

void	large_sort(t_stack *data)
{
	int	half_stack_a;
	int	mid_stack_a;
	int	index;
	int	value_hold;

	while (data->size > 1)
	{
		find_range(data);
		half_stack_a = (data->size - 1) / 2;
		mid_stack_a = get_mean(data);
		index = 0;
		value_hold = 0;
		while (data->a[index] > mid_stack_a && index < data->size - 1)
			index++;
		value_hold = data->a[index];
		position_stack_a(data, half_stack_a, value_hold, index);
		push_b(data);
	}
	push_back_to_a(data);
	check_sorted(data, 1);
}
