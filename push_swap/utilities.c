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



// void print_stack(int *stack, int size)
// {
// 	int index;
// 	index = 0;
// 	while (index < size)
// 	{
// 		ft_putnbr_fd(stack[index], 1);
// 		ft_putchar_fd('\n', 1);
// 		index++;
// 	}
// }
void clean_exit(int *stack, int code)
{
	printf("FAILED \n");
	free(stack);
	exit(code);
}

void push_swap(t_stack *stack_data)
{
	ft_putnbr_fd(stack_data->size, 1);
	printf("\n entered push_swap function \n");
	swap(*stack_data);
	//print_stack(stack_a, size);
	exit(EXIT_SUCCESS);
}
