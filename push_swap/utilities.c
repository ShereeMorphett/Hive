/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:49:27 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/04 11:49:29 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void print_stack(t_stack *stack_data)
{
	int index;
	index = 0;
	printf("stack_a size is: %i \n", stack_data->size);
	while (index < stack_data->size)
	{
		ft_putnbr_fd(stack_data->stack_a[index], 1);
		ft_putchar_fd('\n', 1);
		index++;
	}
	index = 0;
	printf("stack_b size is: %i \n", stack_data->stack_b_size);
	while (index < stack_data->stack_b_size)
	{
		ft_putnbr_fd(stack_data->stack_b[index], 1);
		ft_putchar_fd('\n', 1);
		index++;
	}
}

void clean_exit(t_stack *stack_data)
{
	printf("Entered clean exit\n");
    
	free(stack_data);
	exit(EXIT_SUCCESS);
}

void push_swap(t_stack *stack_data)
{
	stack_data->stack_b = (int *)malloc(sizeof (int) * stack_data->size);
	stack_data->stack_b_size = 0;
	
	//clean_exit(stack_data);
	swap_a(stack_data);
	print_stack(stack_data);
	exit(EXIT_SUCCESS);
}
