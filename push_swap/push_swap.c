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

static int	*process_string(char **new_string, int *stack_a, t_stack *stack)
{
	int	index;
	int	letter;

	index = 0;
	letter = 0;
	while (new_string[index][letter])
	{
		while (new_string[index][letter])
		{
			while (new_string[index][letter])
				letter++;
			index++;
		}
	}
	stack_a = (int *) malloc(sizeof(int) * letter);
	index = 0;
	while (new_string[index] != '\0')
	{
		//check if char is a number
		stack_a[index] = ft_atoi(new_string[index]);
		index++;
	}
	stack->size = index;
	return (stack_a);
}

static void	validate_input(int *stack_a, t_stack *stack_data)
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
			{
				ft_putendl_fd("Error", 1);
				clean_exit(stack_data, 1);
			}
			index++;
		}
		check++;
	}
}

static int	*process_argv(char *argv[], int argc, int *stack_a, t_stack *stack)
{
	int	index;

	index = 0;
	while (index < argc - 1)
	{	
		//check if char is a number
		stack_a[index] = ft_atoi(argv[index + 1]);
		index++;
	}
	stack->size = index;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_data;
	int		*stack_a;
	char	**new_string;

	stack_data = malloc(sizeof (t_stack));
	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		new_string = ft_split(argv[1], ' ');
		stack_a = process_string(new_string, stack_a, stack_data);
	}
	else if (argc > 2)
	{
		stack_a = (int *)malloc(sizeof (int) * (argc - 1));
		process_argv(argv, argc, stack_a, stack_data);
	}
	validate_input(stack_a, stack_data);
	stack_data->stack_a = stack_a;
	push_swap(stack_data);
	clean_exit(stack_data, 1);
	return (0);
}
