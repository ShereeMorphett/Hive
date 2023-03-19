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
	index = 0;
	while (index < data->size)
	{
		if (data->a[index] > data->max)
			data->max = data->a[index];
		index++;
	}
	index = 0;
		while (index < data->size)
	{
		if (data->a[index] < data->min)
			data->min = data->a[index];
		index++;
	}
}

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

// void find_place(t_stack *data)
// {
// 	int index;
// 	int max_index;
	
// 	while (data->stack_b_size != 0)
// 	{
// 		index = 0;
// 		max_index = b_max(data);
// 		ft_printf("\nmax index in B = %i  number is = %i\n\n", max_index, data->b[max_index]);
// 		if (max_index == 1)
// 		{
// 			swap_b(data, 1);
// 			max_index = 0;
// 		}
// 		while (data->b[max_index] > data->a[index])
// 			index++;
// 		ft_printf("\n Max b should be in place %i  before %i \n", index, data->a[index]);
// 		if (index == 0)
// 			push_a(data);
// 		else 
// 			move_a(data, index);
// 		print_stack(data);
// 	}
// }


// /*
// ** Find the next number greater than n in the
// ** stack. Returns 'n' if there's no such number;
// */

// int	closest_above(t_stack *a, int n)
// {
// 	int	k;
// 	int	i;

// 	if (a->top < 0 || n > max(a))
// 		return (n);
// 	i = 0;
// 	k = max(a);
// 	while (i <= a->top)
// 	{
// 		if (a->array[i] > n && a->array[i] < k)
// 			k = a->array[i];
// 		i++;
// 	}
// 	return (k);
// }

// int	closest_below(t_stack *a, int n)
// {
// 	int	k;
// 	int	i;

// 	if (a->top < 0 || n < min(a))
// 		return (n);
// 	i = 0;
// 	k = min(a);
// 	while (i <= a->top)
// 	{
// 		if (a->array[i] < n && a->array[i] > k)
// 			k = a->array[i];
// 		i++;
// 	}
// 	return (k);
// }

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

// /* shift_stack:
// *	After the bulk of the stack is sorted, shifts stack a until the lowest
// *	value is at the top. If it is in the bottom half of the stack, reverse
// *	rotate it into position, otherwise rotate until it is at the top of the
// *	stack.
// */
// static void	shift_stack(t_stack *data)
// {
// 	int	lowest_pos;

// 	lowest_pos = get_lowest_index_position(stack_a);
// 	if (lowest_pos > data->size / 2)
// 	{
// 		while (lowest_pos < data->size)
// 		{
// 			reverse_a(data);
// 			lowest_pos++;
// 		}
// 	}
// 	else
// 	{
// 		while (lowest_pos > 0)
// 		{
// 			rotate_a(data);
// 			lowest_pos--;
// 		}
// 	}
// }

// void	put_in_position(t_stack *a, t_stack *b)
// {
// 	int	top_b;
// 	int	to_move;

// 	top_b = b->array[b->top];
// 	to_move = closest_above(a, top_b);
// 	if (to_move == top_b && a->top >= 0)
// 		to_move = min(a);
// 	smart_rotate_a(a, to_move);
// 	run(PA, a, b);
// }

// void	sort_chunk(t_stack *a, t_stack *b)
// {
// 	while (b->top >= 0)
// 	{
// 		move_min_or_max_to_top(b);
// 		put_in_position(a, b);
// 	}
// }

// void	move_chunk(t_stack *a, t_stack *b, int min, int max)
// {
// 	int	size;

// 	size = max - min + 1;
// 	while (size)
// 	{
// 		move_to_top(a, min, max);
// 		run(PB, a, b);
// 		size--;
// 	}
// }

// size_t	get_chunks(t_stack *a)
// {
// 	size_t	chunks;

// 	chunks = (a->top + 1) / CHUNK_CONSTANT + 1;
// 	return (chunks);
// }
// static int	between(int n, int min, int max)
// {
// 	return (n >= min && n <= max);
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

// void	move_to_top(t_stack *a, int min, int max)
// {
// 	int	i;
// 	int	index[2];

// 	index[0] = find_from_top(a, min, max);
// 	index[1] = find_from_bottom(a, min, max);
// 	if (index[0] < a->top - index[1])
// 		i = index[0];
// 	else
// 		i = index[1];
// 	smart_rotate_a(a, a->array[i]);
// }


// void	move_min_or_max_to_top(t_stack *b)
// {
// 	int	i;
// 	int	index[2];

// 	index[0] = _index(b, min(b));
// 	index[1] = _index(b, max(b));
// 	if (index[0] < b->top - index[1])
// 		i = index[0];
// 	else
// 		i = index[1];
// 	smart_rotate_b(b, b->array[i]);
// }

// void	put_in_position(t_stack *a, t_stack *b)
// {
// 	int	top_b;
// 	int	to_move;

// 	top_b = b->array[b->top];
// 	to_move = closest_above(a, top_b);
// 	if (to_move == top_b && a->top >= 0)
// 		to_move = min(a);
// 	smart_rotate_a(a, to_move);
// 	run(PA, a, b);
// }

// void	sort_chunk(t_stack *a, t_stack *b)
// {
// 	while (b->top >= 0)
// 	{
// 		move_min_or_max_to_top(b);
// 		put_in_position(a, b);
// 	}
// }

// void	move_chunk(t_stack *a, t_stack *b, int min, int max)
// {
// 	int	size;

// 	size = max - min + 1;
// 	while (size)
// 	{
// 		move_to_top(a, min, max);
// 		run(PB, a, b);
// 		size--;
// 	}
// }

// size_t	get_chunks(t_stack *data)
// {
// 	size_t	chunks;

// 	chunks = (a->size + 1) / CHUNK_CONSTANT + 1;
// 	return (chunks);
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
