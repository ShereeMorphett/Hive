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

int check(t_stack *data, int max_size)
{
	if (data->size == max_size)
		return (check_sorted(data, 0));
	else
		return (2);
}

// int b_max(t_stack *data)
// {

// 	return (index);
// }

void	large_sort(t_stack *data)
{
	int	max_size;
	int median;

	find_range(data);
	median = (data->min + data->max) / 2;
	max_size = data->size;
	while (data->size > 3)
	{
		if (do_optimal(data) == 0)
			push_b(data);
	}
	if_three(data, 0);
	do_optimal(data);
	
	while (check(data, max_size) == 2)
	{ 
		if (data->stack_b_size != 0)
		{
			if (do_optimal(data) == 0)
				push_a(data);
		}
	}
//	print_stack(data);
	check_sorted(data,1);
}
