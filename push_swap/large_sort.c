/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:14:59 by smorphet          #+#    #+#             */
/*   Updated: 2023/03/22 13:15:07 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int find_cost(t_stack *data)
{
	int index;

	index = 0;
	if (data->b[0] > data->a[0])
		return (0);
	while (index < data->size - 1)
	{
		if (data->b[0] > data->a[index])
			index++;
		if (data->b[0] < data->a[index] && data->b[0] < data->a[index + 1])
			break;
	}
	return (index);
}

void	do_moves(t_stack *data)
{
	int cost;
	int temp_cost;

	while (do_optimal(data) != 0) 
		;
	
	cost = find_cost(data);
	if (cost == 0)
		push_a(data);
	if (cost <= data->size / 2)
	{
		temp_cost = cost;
		while (cost-- != 0)
			rotate_a(data, 1);
		push_a(data);
		while (temp_cost-- != 0)
			reverse_a(data, 1);
	}
	else if (cost > data->size / 2)
	{ 
		cost = data->size - cost;	
		temp_cost = cost;
		while (cost >= 0)
		{
			reverse_a(data, 1);
			cost--;
		}
		while (temp_cost-- > 0)
			rotate_a(data, 1);
		if (cost == 0)
		{
			push_a(data);
			rotate_a(data, 1);
		}
	}
}

void	large_sort(t_stack *data)
{
	int max_size;

	max_size = data->size;
	find_range(data);
	do_optimal(data);
	while (data->stack_b_size != 2)
	{
		if (data->a[0] != data->max)
			push_b(data);
		else
			rotate_a(data, 1);
	}
	while (data->size > 3)
	{
		while (do_optimal(data) != 0) 
			;
		push_b(data);
	}
	if_three(data, 0);
	//////////////////////////////////////////////////////////////////////
	while (data->stack_b_size != 0)
	{
		do_moves(data);
		//push_a(data);
	}
	print_stack(data);
	check_sorted(data, 1);
}