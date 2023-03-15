/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:06 by smorphet          #+#    #+#             */
/*   Updated: 2023/03/14 13:10:08 by smorphet         ###   ########.fr       */
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

		while (index < data->size)
	{
		if (data->a[index] < data->min)
			data->min = data->a[index];
		index++;
	}
}

void chunking_back(t_stack *data, int chunk)
{
	int index;

	data->found = 0;
	index = data->size - 1;
	while (index >= 0 && data->found == 0)
	{
		if (data->a[index] <= chunk)
		{
			data->second_hold = index;
			data->found = 1;
			index--;
		}
		else
			index--;
	}
}

void chunking_forward(t_stack *data, int chunk)
{
	int index;
	
	index = 0;
	data->found = 0;
	while (index <= data->size && data->found == 0)
	{
		if (data->a[index] <= chunk)
		{
			data->found = 1;
			data->first_hold = index;
			index++;
		}
		else
			index++;
	}
}
