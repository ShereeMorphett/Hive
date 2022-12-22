/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:44:52 by smorphet          #+#    #+#             */
/*   Updated: 2022/12/22 09:44:58 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
#include "libft.h"

typedef struct s_list
{
	int			*content;
	struct s_list	*next;
	struct s_list	*prev;
	
}					t_list;

void swap(t_list *stack, char id);
void ss(t_list stack_a, t_list stack_b);
void push(t_list stack, char id);
void rotate(t_list stack, char id);
void rr(t_list stack_a, t_list stack_b);
void rev_rotate(t_list stack, char id);
void rrr(t_list stack_a, t_list stack_b);

#endif