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
		if ((data->a[0] > data->a[1] && data->a[1] < data->a[2]) && data->a[0] > data->a[2])
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
			swap_a(data, exit);
		
		if (!check_sorted(data, exit))
			return (0);
	}
	return (0);
}

static int find_place(t_stack *data) {
    int index;

    index = 0;
    while (index < data->size - 1) {
        if (data->a[index] > data->b[0]) {
            break;
        }
        index++;
    }
    return index;
}

void	push_to_three(t_stack *data)
{
	int	index;
	int middle;

	middle = data->max - data->min;
	index = 0;
	while (data->size > 3 && index < data->size)
	{
		if (data->a[index] <= middle)
		{
			push_b(data);
		}
		else
			rotate_a(data, 1);
		index++;
	}
	while (data->size > 3)
	{
		push_b(data);
	}
}

void if_five(t_stack *data)
{
	int sorted_index;
	//int count;

	find_range(data);
	push_to_three(data);
	if_three(data, 0);
	if (data->b[0] < data->b[1])
		swap_b(data, 1);
	print_stack(data);
		sorted_index = find_place(data);
		ft_printf("\n\n b[0] = %i and belongs at index %i\n\n", data->b[0], sorted_index);
		if (sorted_index == 0)
			push_a(data);
		else if (sorted_index == 1)
		{
			push_a(data);
			swap_a(data, 1);
		}
		// else if (sorted_index == 2 || sorted_index == 3)
		// {
		// 	count = sorted_index;
		// 	while (count != 0)
		// 	{
		// 		reverse_a(data, 1);
		// 		count--;
		// 	}
		// 	push_a(data);

		// 	while (--sorted_index != 0)
		// 	{
		// 		rotate_a(data, 1);
		// 	}
		// }
		else if (sorted_index == data->size - 1)
		{
			push_a(data);
			rotate_a(data, 1);
		}
	print_stack(data);
}


