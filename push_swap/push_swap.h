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
#include <stdio.h> // 	REMOVE BEFORE SUBMISSION

typedef struct s_stack {
    int size;
    int *stack_a;
    int *stack_b;
} t_stack;

void clean_exit(int *stack, int code);
void push_swap(t_stack *stack_data);
char swap(t_stack stack_data);

#endif
