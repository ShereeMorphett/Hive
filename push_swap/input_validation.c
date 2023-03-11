/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:27:40 by smorphet          #+#    #+#             */
/*   Updated: 2023/03/03 10:27:42 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	validate_input(int *stack_a, t_stack *stack_data)
{
	int	index;
	int	check;

	check = 0;
	while (check < stack_data->size)
	{
		index = check + 1;
		while (index < stack_data->size)
		{
			if (stack_a[check] == stack_a[index])
				clean_exit(stack_data, 3);
			index++;
		}
		check++;
	}
}

int	check_number(char *string, t_stack *stack)
{
	int	num;
	int	index;

	index = 0;
	num = ft_atoi(string);
	while (string[index] != '\0')
	{
		if (string[index] == '-' || string[index] == '+')
			index++;
		if (string[index] < '0' || string[index] > '9')
			clean_exit(stack, 3);
		index++;
	}
	if (string[0] != '-' && num < 0)
		return (0);
	if (string[0] == '-' && num >= 0)
		return (0);

	else
		return (1);
}
