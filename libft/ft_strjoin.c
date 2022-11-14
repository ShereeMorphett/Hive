/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:27:31 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/06 12:51:29 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
    size_t    index_s1;
    size_t    index_s2;
    char    *str;

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
