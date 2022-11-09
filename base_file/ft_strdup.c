/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:12:07 by smorphet          #+#    #+#             */
/*   Updated: 2022/07/07 10:57:39 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*allocated;
	char	*current;

	allocated = (char *) malloc(sizeof(char *) * ft_strlen(src) + 1);
	if (!(allocated))
		return (NULL);
	current = allocated;
	while (*src)
	{
		*current++ = *src++;
	}
	*current = '\0';
	return (allocated);
}
