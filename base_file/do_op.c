/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 08:33:20 by smorphet          #+#    #+#             */
/*   Updated: 2022/07/17 08:33:31 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "evalexp.h"

int    do_op(int nb1, int nb2, char operator)
{
    printf("do-op starts here: \n nm 1: %d  nm 2: %d   operator: %c\n", nb1, nb2, operator);
    if (operator == '+')
        return (nb1 + nb2);
    else if (operator == '-')
        return (nb1 - nb2);
    else if (operator == '/')
        return (nb1 / nb2);
    else if (operator == '*')
        return (nb1 * nb2);
    else if (operator == '%')
        return (nb1 % nb2);
    return (0);
}
