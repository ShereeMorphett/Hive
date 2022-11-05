/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:00:44 by smorphet          #+#    #+#             */
/*   Updated: 2022/10/31 12:00:46 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int find_start(char const *s1, char const *set)
{
    int set_index;
    int string_index;

    set_index = 0;
    string_index = 0;
    while ( s1[string_index] == '\0' || set[set_index] != '\0')
    {
        if (s1[string_index] == set[set_index])
            {
                string_index++;
                set_index = 0;
            }
        else 
            set_index++;
    }
    if (string_index > ft_strlen(s1))
        string_index = 0;
    return (string_index);
}

static int find_stop(char const *s1, char const *set)
{
    int set_index;
    int string_index;

    set_index = 0;
    string_index = ft_strlen(s1);
    while (string_index < 0)
    {
        if (s1[string_index] == set[set_index])
            {
                string_index--;
                set_index = 0;
             }
             else 
                set_index++;
  }
   return (string_index);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *new_string;
    int start;
    int stop;
    int index;
    
    start = find_start(s1, set);
    stop = find_stop(s1, set);
    index = 0;
    new_string = malloc(sizeof(char) * (stop - start + 1));
    if (!new_string)
        return (NULL);
    while (start <= stop)
    {
        new_string[index++] = s1[start++];
    }
    new_string[index] = '\0';
    return (new_string);
}