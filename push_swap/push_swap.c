/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:38:16 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/06 15:40:12 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int *process_string(char **new_string, int *stack_a, t_stack *data)
{
	int index;
	int letter;

	index = 0;
	letter = 0;
	while (new_string[letter])
		letter++;
	if (*new_string[index] == '\0')
		clean_exit(data, 2);
	stack_a = (int *)malloc(sizeof(int) * letter);
	while (*new_string[index] != '\0')
	{
		if (!check_number(new_string[index], data))
			clean_exit(data, 3);
		stack_a[index] = ft_atoi(new_string[index]);
		index++;
	}
	data->size = index;
	if (data->size == 1)
		clean_exit(data, 2);
	return (stack_a);
}

static int *process_argv(char *argv[], int argc, int *stack_a, t_stack *stack)
{
	int index;

	index = 1;
	while (index < argc)
	{
		if (!check_number(argv[index], stack))
			clean_exit(stack, 3);
		index++;
	}
	index = 0;
	while (index < argc - 1)
	{
		stack_a[index] = ft_atoi(argv[index + 1]);
		index++;
	}
	stack->size = index;
	return (0);
}

int main(int argc, char *argv[])
{
	t_stack *data;
	int *stack_a;
	char **new_string;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	data = malloc(sizeof(t_stack));
	stack_a = NULL;
	if (argc == 2)
	{
		new_string = ft_split(argv[1], ' ');
		stack_a = process_string(new_string, stack_a, data);
	}
	else if (argc > 2)
	{
		stack_a = (int *)malloc(sizeof(int) * (argc));
		process_argv(argv, argc, stack_a, data);
	}
	if (data->size == 1)
		clean_exit(data, 1);
	validate_input(stack_a, data);
	data->a = stack_a;
	push_swap(data);
	clean_exit(data, 1);
	return (0);
}
