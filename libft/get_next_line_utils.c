/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:55:52 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/15 12:09:04 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*SHEREE THESE ARE FINE, THEY PASSED LIBFT DO NOT MESS WITH THEM.....THEY DO WHAT YOU WANT!*/

char *gnl_strjoin(char *s1, char *s2)
{
    size_t index_s1;
    size_t index_s2;
    char *str;

    if (!s1)
    {
        s1 = (char *)malloc(1 * sizeof(char));
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    index_s1 = -1;
    index_s2 = 0;
    if (s1)
        while (s1[++index_s1] != '\0')
            str[index_s1] = s1[index_s1];
    while (s2[index_s2] != '\0')
        str[index_s1++] = s2[index_s2++];
    str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    free(s1);
    return (str);
}