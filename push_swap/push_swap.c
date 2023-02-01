/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:30:36 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/01 10:30:39 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

static int *process_argv(char *argv[], int *stack_a)
{
	int index;

	index = 0;

	while (argv[index])
		index++;
	
	stack_a = (int*) malloc(sizeof(int) * index);
	index = 1;

	while (argv[index])
	{
		stack_a[index] = ft_atoi(argv[index]);
		ft_putnbr_fd(stack_a[index], 1);
		ft_putchar_fd('\n', 1);
		index++;
	}

	return (stack_a); 
}

static int *process_string(char **new_string, int *stack_a)
{
	int index;
	int c_index;

	c_index = 0;
	index = 0;
	while (new_string[index])
	{
		c_index = 0;
		while(new_string[index][c_index])
			c_index++;
		index++;
	}
	stack_a = (int*) malloc(sizeof(int) * index);
	index = 0;
	while (new_string[index])
	{
		stack_a[index] = ft_atoi(new_string[index]);
		ft_putnbr_fd(stack_a[index], 1);
		ft_putchar_fd('\n', 1);
		index++;
	}
	return (stack_a); 
}

static void free_newstring(char **new_string)
{
	int index;
	index = 0;
	while (new_string[index])
		{
			free(new_string[index]);
			index++;
		}
	free(new_string);
}

int main(int argc, char *argv[])
{
	char **new_string;
	int *stack_a;
	
	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		new_string = ft_split(argv[1], ' ');
		stack_a = process_string(new_string, stack_a);
		free_newstring(new_string);
	}
	else if (argc > 2)
		stack_a = process_argv(argv, stack_a);
	
	//validate_input(stack_a);

	free(stack_a);
	return (0);
}