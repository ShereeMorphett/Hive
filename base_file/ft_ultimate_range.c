/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 08:32:43 by smorphet          #+#    #+#             */
/*   Updated: 2022/07/07 08:36:51 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int    length;
    int    *array;
    int    *val;

    length = max - min;
    if (min >= max)
        return (0);
    array = (int *)malloc(sizeof(int) * length);
    val = array;
    while (min < max)
    {
        *(val++) = min++;
    }
    return (array);
}

int    ft_ultimate_range(int **range, int min, int max)
{
    *range = ft_range(min, max);
        if (min >= max)
        return (0);
    
    return (max - min);
}
