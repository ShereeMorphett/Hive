/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:17:49 by smorphet          #+#    #+#             */
/*   Updated: 2022/06/30 05:56:29 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int    ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}