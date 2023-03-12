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
	}
}
/*Sends the top two numbers from Stack A to Stack B.
 Uses the logic from 3 Random Numbers to sort the numbers in A.
  Makes sure Stack A can correctly accept the numbers from Stack B.*/

void	if_five(t_stack *data)
{
	int max;
	int index;

	index = 0;
	max = 0;
	ft_putendl_fd("entered if_five", 1);
	while (data->a[index] <= data->size)
	{
		if (data->a[index] > max)
			max = data->a[index];
		index++;
	}
	ft_putnbr_fd(max, 1);
	ft_putchar_fd('\n', 1);
}

