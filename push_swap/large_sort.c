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
/* a function that shows how many rotations are needed to be at top of stack

*/


int cost_to_move_to_top_b(t_stack *data, int index_a)
{
	int index_b;
	int cost;

	index_b = 0;
	while (index_b < data->stack_b_size)
	{	
		if (data->a[index_a] < data->b[index_b])
			index_b++;
		else
			break;
	}
	if (index_b < (data->stack_b_size / 2))
	{
		cost = (data->stack_b_size - 1) - index_b;
		return (cost);
	}
	else
		return (index_b + 1);
}

int cost_to_move_to_top_a(t_stack *data, int index_a)
{
	if (index_a > (data->size / 2))
		return ((data->size - 1) - index_a);
	else
		return (index_a);
}

void find_cheapest(t_stack *data)
{
	int index;
	int cheapest_index;
	int lowest_cost;
	int cost;

	if (data->b[0] < data->b[1])
		swap_b(data, 1);
	index = 0;
	lowest_cost = 2147483647;
	cheapest_index = index;
	while (index < data->size)
	{
		cost = cost_to_move_to_top_b(data, index);
		cost += cost_to_move_to_top_a(data, index);
		ft_printf("\n\nnumber: %i	cost to move to correct position in b %i\n\n", data->a[index], cost);
		if (lowest_cost > cost)
		{
			lowest_cost = cost;
			cheapest_index = index;
		}
		index++;
	}
	ft_printf("\n\n the cheapest number: %i	cost to move to correct position in b %i\n\n", data->a[cheapest_index], lowest_cost);
	return(cheapest_index);
}

void	large_sort(t_stack *data)
{
	int cheapest_index;
	find_range(data);
	while (data->stack_b_size != 2)
	{
		push_b(data);
	}
	cheapest_index = find_cheapest(data);
	// from here i need to take that information and action it into the correct place, the create a loop to sort all but 3 from A into B
	
	print_stack(data);
}