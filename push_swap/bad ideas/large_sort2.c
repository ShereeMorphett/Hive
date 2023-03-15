/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:24:50 by smorphet          #+#    #+#             */
/*   Updated: 2023/03/07 12:24:53 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// static void moving_to_top(t_stack *data)
// {

// 	if (data->found != 0)
// 	{
// 		length = data->size - data->second_hold - 1;
// 		if (length < data->first_hold)
// 		{
// 			while(length >= 0)
// 			{
// 				reverse_a(data, 1);
// 				length--;
// 			}
// 		}
// 		else 
// 		{
// 			length = data->first_hold - 1;	
// 			while(length >= 0)
// 			{
// 				rotate_a(data, 1);
// 				length--;
// 			}
// 		}
// 		sorting_b(data);
// 	}
// }

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

void if_other(t_stack *data)
{
	int pivot;
	int index;
	int total;

	index = 0;
	total = data->size;
	ft_printf("\n~~~entered if_other~~~\n", data->size);
	find_range(data);
	pivot = (data->min + data->max) / 2;
	
	while (total >= 0)
	{
		if (pivot > data->a[index])
			push_b(data);
		else
			rotate_a(data,1);
		total--;
	}
	check_sorted(data);
}
