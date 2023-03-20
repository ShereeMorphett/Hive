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
	index = 1;
	while (index < data->size)
	{
		if (data->a[index] > data->max)
			data->max = data->a[index];
		if (data->a[index] < data->min)
			data->min = data->a[index];
		index++;
	}
}