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

void	if_three(t_stack *data)
{
	while (data->a)
	{
		if ((data->a[0] > data->a[1] && data->a[1] < data->a[2]) && data->a[0] > data->a[2])
			rotate_a(data, 1);
		else if (data->a[0] > data->a[1] && data->a[1] > data->a[2])
		{
			swap_a(data, 1);
			check_sorted(data);
			reverse_a(data, 1);
		}
		else if (data->a[0] < data->a[1] && data->a[1] > data->a[2])
		{
			reverse_a(data, 1);
			check_sorted(data);
			swap_a(data, 1);
		}
		else if (data->a[0] > data->a[1] && data->a[1] < data->a[2])
			swap_a(data, 1);
		
		check_sorted(data);
	}
}

