/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_whitespace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:28:43 by smorphet          #+#    #+#             */
/*   Updated: 2022/07/17 11:06:49 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "evalexp.h"
#include <stdio.h>

char    *remove_whitespaces(char *str)
{
    int        old_str_ind;
    int        new_str_ind;
    char       *new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
    int index = 0;
    
    printf("old string before whitespace %s \n", str);
    old_str_ind = 0;
    new_str_ind = 0;
    while (str[old_str_ind ] != '\0')
    {
        if (str[old_str_ind] != ' ' && str[old_str_ind ] != '\t')
        {
            new_str[new_str_ind ] = str[old_str_ind];
            new_str_ind++;
        }
        old_str_ind++;
    }
    new_str[new_str_ind] = '\0';
    while (new_str[index] != '\0')
    {
        printf("new string %c \n", new_str[index]);
        index++;
    }
        return (new_str);
}
