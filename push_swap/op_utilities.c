/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:01:40 by smorphet          #+#    #+#             */
/*   Updated: 2023/03/22 13:01:42 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	if_both(t_stack *data)
{
	int	changed;

	changed = 0;
	if (data->stack_b_size > 1 && data->size > 1)
	{
		if (data->a[0] > data->a[1] && data->b[0] < data->b[1])
		{
			swap_both(data);
			changed = 1;
		}
		if (data->a[0] == data->max && data->b[0] == data->min)
		{	
			rotate_both(data);
			changed = 1;
		}
	}
	return (changed);
}

static int	stack_b_op(t_stack *data)
{
	int	changed;

	changed = 0;
	if (data->stack_b_size > 2 && data->b[0] == data->min)
	{
		rotate_b(data, 1);
		changed = 1;
	}
	if (data->stack_b_size >= 2)
	{
		if (data->b[0] < data->b[1])
		{
			swap_b(data, 1);
			changed = 1;
		}
	}
	return (changed);
}

int	do_optimal(t_stack *data)
{
	int	changed;

	changed = 0;
	if (data->stack_b_size > 1 && data->size > 1)
		changed = if_both(data);
	if (data->size > 2)
	{
		if (data->a[data->size - 1] == data->min)
		{
			reverse_a(data, 1);
			changed = 1;
		}
		if (data->a[0] == data->max)
		{
			rotate_a(data, 1);
			changed = 1;
		}
	}
	if (data->a[0] > data->a[1])
	{
		swap_a(data, 1);
		changed = 1;
	}
	changed = stack_b_op(data);
	return (changed);
}
