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
		if ((data->a[0] > data->a[1] && data->a[1] < data->a[2]) && \
			data->a[0] > data->a[2])
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
			swap_a(data, 1);
		if (!check_sorted(data, exit))
			return (0);
	}
	return (0);
}

void	if_five(t_stack *data)
{
	int	max_size;

	max_size = data->size;
	find_range(data);
	while (data->size > 2)
	{
		if (do_optimal(data) == 0)
			push_b(data);
	}		
	while (data->stack_b_size != 0)
	{
		if (data->stack_b_size > 1 && data->b[0] < data->b[1])
			swap_b(data, 1);
		while (do_optimal(data) != 0)
			;
		if (data->a[0] < data->a[1])
			push_a(data);
		if (data->a[0] > data->a[1])
			swap_a(data, 1);
	}
	check_sorted(data, 1);
}
