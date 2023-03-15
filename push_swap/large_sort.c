/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:58:24 by smorphet          #+#    #+#             */
/*   Updated: 2023/03/15 12:58:26 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void find_range(t_stack *data)
{
	int index;

	data->max = data->a[0];
	data->min = data->a[0];
	index = 0;
	while (index < data->size)
	{
		if (data->a[index] > data->max)
			data->max = data->a[index];
		index++;
	}
	index = 0;
		while (index < data->size)
	{
		if (data->a[index] < data->min)
			data->min = data->a[index];
		index++;
	}
}

// void find_place(t_stack *data)
// {
// 	int index;
// 	index = 0;

// 	while (data->b[0] > data->a[index])
// 		index++;
// 	if (index >= 1)
// 	{
// 		push_a(data);
// 		swap_a(data, 1);
// 	}
// }

void if_other(t_stack *data)
{
	int index;

	index = 0;
	find_range(data);
	while (data->size != 3)
	{
		if (data->a[0] == data->max)
			rotate_a(data, 1);
		else
			push_b(data);
	}
	if (data->size == 3)
		if_three(data, 0);
	while (data->stack_b_size != 0)
	{
		if (data->a[1] < data->a[0])
			swap_a(data, 1);
		if (data->b[0] < data->a[0])
			push_a(data);
	}
	print_stack(data);
	check_sorted(data, 1);
}