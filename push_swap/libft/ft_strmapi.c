/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:48:38 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/04 17:34:12 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned
int, char))
{
	unsigned int	index;
	char			*str;

	index = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str)
	{
		while (s[index])
		{
			str[index] = f(index, s[index]);
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}
