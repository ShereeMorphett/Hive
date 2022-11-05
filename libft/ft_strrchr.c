/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:35:38 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/04 17:27:32 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	index;

	index = ft_strlen(str);
	if (str == '\0')
		return (NULL);
	while (index >= 0)
	{
		if (str[index] == c)
			return ((char *) &str[index]);
		index--;
	}
	if (index == 0)
		return (NULL);
	return (NULL);
}
