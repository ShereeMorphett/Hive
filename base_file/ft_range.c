/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 08:17:00 by smorphet          #+#    #+#             */
/*   Updated: 2022/07/07 08:20:02 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	length;
	int	*array;
	int	*val;

	length = max - min;
	if (min >= max)
		return (NULL);
	array = (int *)malloc(sizeof(int) * length);
	val = array;
	while (min < max)
	{
		*(val++) = min++;
	}
	return (array);
}
