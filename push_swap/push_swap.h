/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:30:42 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/01 10:30:44 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_stack {
	int	size;
	int	*a;
	int	*b;
	int	stack_b_size;
	int first_hold;
	int second_hold;
	int found;
	int place;
	int max;
	int min;
}	t_stack;

int		check_number(char *string, t_stack *stack);
int		check_sorted(t_stack *stack_data, int exit);
void	validate_input(int *stack_a, t_stack *stack_data);
void	clean_exit(t_stack *data, int error);
void	push_swap(t_stack *stack_data);
void	swap_a(t_stack *stack_data, int print);
void	swap_b(t_stack *stack_data, int print);
void	swap_both(t_stack *stack_data);
void	push_a(t_stack *stack_data);
void	push_b(t_stack *stack_data);
void	rotate_a(t_stack *stack_data, int print);
void	rotate_b(t_stack *stack_data, int print);
void	rotate_both(t_stack *stack_data);
void	reverse_a(t_stack *stack_data, int print);
void	reverse_b(t_stack *stack_data, int print);
void	reverse_both(t_stack *stack_data);
int		if_three(t_stack *data, int exit);
void	if_two(t_stack *data);
void	if_five(t_stack *data);

void	if_other(t_stack *data);
void 	chunking_forward(t_stack *data, int chunk);
void 	chunking_back(t_stack *data, int chunk);
void 	find_range(t_stack *data);
void 	sorting_b(t_stack *data);
void	push_to_three(t_stack *data);

void	print_stack(t_stack *stack_data);

#endif
