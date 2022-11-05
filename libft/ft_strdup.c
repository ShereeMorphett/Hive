/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:06:54 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/04 17:14:18 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstring;
	int		index;

	index = 0;
	newstring = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (newstring)
	{
		if (s == '\0')
		{
			return (NULL);
		}
		while (s[index] != '\0')
		{
			newstring[index] = s[index];
			index++;
		}
		newstring[index] = '\0';
	}
	return (newstring);
}
