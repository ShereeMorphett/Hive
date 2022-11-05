/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:11:35 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/01 10:11:37 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    char *first;
    int h_index;
    int n_index;

    h_index = 0;
    if (needle[0] == '\0')
        return ((char *)haystack);
    
    while (haystack[h_index] != '\0' && len != 0)
        {
            n_index = 0;
    
            while (needle[n_index] == haystack[h_index] && needle[n_index] != '\0')
                {
                  if( n_index == 0 && needle[n_index] == haystack[h_index])
                   {
                      first = (char *) &haystack[h_index];
                   }
                	n_index++;
					h_index++;
                    len--;
                }
            h_index++;
            len--;
        }
    return (first);
    }
