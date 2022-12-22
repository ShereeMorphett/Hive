/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:45:07 by smorphet          #+#    #+#             */
/*   Updated: 2022/12/22 09:45:10 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int check_input(int argc, char* argv[])
{
	int index;
	int check;

	check = 1;
	while (check <= argc)
	{
		index = 1;

		while(index <= argc)
		{
			if (argv[check] == argv[index])
				return (1);
			index++;
		}
		check++;
	}
}

void main(int argc, char *argv[])
{
	t_list *new;
	t_list **stack_a;
	t_list **stack_b;
	t_list **moves;
	int index;
		
	index = 1;
	if (argc <= 1)
		return;
	if(check_input(argc, argv) != 0)
	{
		write(2, "Error\n", 6);
		return;
	}
	while(argc > index)
	{
		new = ft_lstnew(argv[index]);
		t_lstadd_back(**stack_a, *new);
		argv[index++];	
	}
}