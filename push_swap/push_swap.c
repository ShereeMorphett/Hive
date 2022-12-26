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

#include <stdio.h> // DELETE THIS AND THE FT_PRINTLIST

static int convert_input(int argc, char* argv[], int *checked_input)
{
	int index;

	index = 0;
	while (index < argc)
	{
		checked_input[index] = ft_atoi(argv[index]);
		index++;
	}
	return (0);
}

// static void ft_printlist(t_list *list)
// {
// 	while (list)
// 	{
// 		printf("%i", *list->content);
// 		list = list->next;
// 	}
// }


int main(int argc, char *argv[])
{
	//t_list *new;
	//t_list **stack_a;
	//t_list **stack_b;
	//t_list **moves;
	int index;
	int *checked_input;

	
	index = 1;
	checked_input = (int*)malloc((argc) * sizeof(int));
	//stack_a = NULL;
	if (argc <= 1)
		return (0);
	*checked_input = convert_input(argc, argv, checked_input);

	while (index < argc)
	{
		printf("%i\n", checked_input[index]);
		index++;
	}

	return (0);
}