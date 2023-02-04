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


static int *process_argv(char *argv[], int argc, int *stack_a)
{
	int index;
	int size;

	size = argc - 1;
	index = 1;

	stack_a = (int*) malloc(sizeof(int) * size);
	index = 1;
	while (argv[index])
	{
		stack_a[index - 1] = ft_atoi(argv[index]);
		ft_putnbr_fd(stack_a[index - 1], 1);
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

static void validate_input(int *stack_a, t_stack stack_data)
{
    int index;
    int check;

    check = 0;
    while (stack_a[check])
        check++;
    stack_data.size = check;
    check = 0;
    while (check < stack_data.size)
    {
        index = check + 1;
        while (index < stack_data.size)
        {
            if (stack_a[check] == stack_a[index])
            {
				clean_exit(stack_a, EXIT_FAILURE);
            }
            index++;
        }
        check++;
    }
}

int main(int argc, char *argv[])
{
	char **new_string;
	t_stack *stack_data;
	int *stack_a;
	
	stack_data = malloc(sizeof (t_stack));
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
		stack_a = process_argv(argv, argc, stack_a);
	validate_input(stack_a, *stack_data);
	stack_data->stack_a = stack_a;
	printf("%i \n", stack_data->stack_a[0]);
	free(stack_a);
	return (0);
}