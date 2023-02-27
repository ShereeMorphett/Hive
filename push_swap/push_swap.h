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

# include <stdio.h>

typedef struct s_stack {
	int	size;
	int	*stack_a;
	int	*stack_b;
	int	stack_b_size;
}	t_stack;

void	clean_exit(t_stack *stack_data, int error);
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

#endif
