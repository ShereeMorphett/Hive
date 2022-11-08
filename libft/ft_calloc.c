/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:01:03 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/08 10:45:36 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*pointer;
	size_t	bytes;

	if (nitems == 0 || size == 0)
		return (ft_calloc(1, 1));
	bytes = nitems * size;
	if (bytes / size != nitems)
		return (NULL);
	pointer = malloc(nitems * size);
	if (pointer == NULL)
		return (pointer);
	ft_bzero(pointer, size * nitems);
	return (pointer);
}
