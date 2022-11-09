/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:45:35 by smorphet          #+#    #+#             */
/*   Updated: 2022/07/08 06:47:43 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_rot42(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 'a' && str[index] <= 'z')
		{
			if (str[index] + 16 <= 'z')
				str[index] += 16;
			else
				str[index] -= 10;
		}
		else if (str[index] >= 'A' && str[index] <= 'Z')
		{
			if (str[index] + 16 <= 'Z')
				str[index] += 16;
			else
				str[index] -= 10;
		}
		index++;
	}
	return (str);
}
