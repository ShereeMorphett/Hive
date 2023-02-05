/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:47:48 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/05 13:21:05 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

/* Assignment name  : ft_range

Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3. */


#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	*res;
	int	size;
	int	i;

	if (start <= end)
		size = end - start + 1;
	else
		size = start - end + 1;
	i = 0;
	res = (int *) malloc(size * sizeof(int));
	if (!res)
		return (NULL);
	if (start <= end)
	{
		while (start <= end)
		{
			res[i++] = start;
			start++;
		}
	}
	else
	{
		while (start >= end)
		{
			res[i++] = start;
			start--;
		}
	}
	return (res);
}

int main(void)
{
	int *array;
	int size;
	int start = 0;
	int finish = -3;

	array = ft_range(start, finish);
	if (!array)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	size = (start <= finish) ? finish - start + 1 : start - finish + 1;
	int index = 0;
	while (index < size)
	{
		printf("%i ", array[index]);
		index++;
	}
	free(array);
	return (0);
}
