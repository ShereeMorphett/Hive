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
// }
// //////////////////////////////////////////////////////////////////////////////////////////////////////////
// /*
// ** Put the number 'n' at the top of the stack,
// ** in the least amount of moves possible (RRA
// ** or RA). Do nothing if 'n' isn't on stack;
// */

// void	smart_rotate_a(t_stack *a, int n)
// {
// 	int	find;

// 	find = a->top;
// 	while (find >= 0 && a->array[find] != n)
// 		find--;
// 	if (find < 0)
// 		return ;
// 	else if (find < a->top / 2)
// 		run_n(RRA, a, NULL, find + 1);
// 	else
// 		run_n(RA, a, NULL, a->top - find);
// }

// void	smart_rotate_b(t_stack *b, int n)
// {
// 	int	find;

// 	find = b->top;
// 	while (b->array[find] != n && find >= 0)
// 		find--;
// 	if (find < 0)
// 		return ;
// 	else if (find < b->top / 2)
// 		run_n(RRB, NULL, b, find + 1);
// 	else
// 		run_n(RB, NULL, b, b->top - find);
// }

// static int	find_from_top(t_stack *a, int min, int max)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= a->top)
// 	{
// 		if (between(a->array[i], min, max))
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// static int	find_from_bottom(t_stack *a, int min, int max)
// {
// 	int	i;

// 	i = a->top;
// 	while (i >= 0)
// 	{
// 		if (between(a->array[i], min, max))
// 			return (i);
// 		i--;
// 	}
// 	return (-1);
// }
//////////////////////////////////////////////////////////////////////////////////////////////////////////
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

// void	push_to_three(t_stack *data)
// {
// 	int	index;
// 	int middle;

// 	middle = (data->max - data->min) / 2 + data->min;
// 	index = 0;
// 	while (data->size > 3 && index < data->size)
// 	{
// 		if (data->a[index] >= middle)
// 			push_b(data);
// 		else
// 			rotate_a(data, 1);
// 		index++;
// 	}
// 	while (data->size > 3)
// 	{
// 		if (data->a[index] != data->min)
// 			push_b(data);
// 		else
// 			rotate_a(data, 1);
// 	}
// }

// static int find_place(t_stack *data) {
//     int index;

//     index = 0;
//     while (index < data->size - 1) {
//         if (data->a[index] > data->b[0]) {
//             break;
//         }
//         index++;
//     }
//     return index;
// }

// void 	move_a(t_stack *data, int index)
// {	
// 	int count;

// 	count = index + 1;
// 	if (data->size / 2 >= index)
// 	{
// 		while (count-- != 0)
// 		{
// 			reverse_a(data, 1);
// 		}
// 		push_a(data);
// 	}
// 	else
// 	{
// 		while (count-- != 0)
// 		{
// 			rotate_a(data, 1);
// 		}
// 		push_a(data);
// 	}
// }

// static int b_max(t_stack *data)
// {
// 	int index;
// 	int max_index;

// 	index = 0;
// 	max_index = 1;
// 	if (data->stack_b_size == 1)
// 		return (0);
// 	while (index < data->stack_b_size)
// 	{
// 		if (data->b[index] > data->b[max_index])
// 		{
// 			max_index = index;
// 			index++;
// 		}
// 		else
// 			index++;
// 	}
// 	return (max_index);
// }

// void 	move_a(t_stack *data, int index)
// {	
// 	int count;

// 	count = index;
// 	if (data->size / 2 >= index)
// 	{
// 		while (count != 0)
// 		{
// 			reverse_a(data, 1);
// 			count--;
// 		}
// 		push_a(data);
// 	}
// }


void if_other(t_stack *data)
{
// 	int		chunk_min;
// 	int		chunk_max;
// 	int		chunks;
// 	int		step;

// 	find_range(data)
// 	chunks = get_chunks(data);
// 	chunk_max = data->max;
// 	step = (data->size + 1) / chunks;
// 	while (chunks >= 1)
// 	{
// 		if (chunks == 1)
// 			limit_min = min(a);
// 		else
// 			limit_min = limit_max - step + 1;
// 		move_chunk(a, b, limit_min, limit_max);
// 		sort_chunk(a, b);
// 		limit_max = limit_min - 1;
// 		chunks--;
// 	}
	print_stack(data);
	//smart_rotate_a(a, min(a));
}
