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

void if_other(t_stack *data)
{
	ft_printf("entered if_other function\n");

	int pivot;
	int index;
	int count;

	count = data->size;
	index = 0;
	pivot = data->a[(data->size - 1) / 2];
	while (count != 0)
	{
		if (data->a[index] < pivot)
			push_b(data);
		if (data->a[index] >= pivot)
			rotate_a(data, 1);
		count--;
	}
	pivot = data->a[(data->size - 1) / 2];
	count = data->stack_b_size;
	while (count != 0)
	{
		if (data->b[index] > pivot)
			push_a(data);
		if (data->b[index] <= pivot)
			rotate_b(data, 1);
		count--;
	} 	
}
