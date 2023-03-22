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
		return (1);
}

void	large_sort(t_stack *data)
{
	ft_printf("entered into large_sort\n");
	int	max_size;

	max_size = data->size;
	find_range(data);
	while (data->size > 2)
	{
		if (do_optimal(data) == 0)
			push_b(data);
	}	
	while (check(data, max_size) != 0)
	{
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
	}
	//print_stack(data);
	check_sorted(data, 1);
}
