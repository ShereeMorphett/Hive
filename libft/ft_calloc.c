/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:01:03 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/04 17:06:51 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*pointer;

	pointer = malloc(nitems * size);
	if (pointer == NULL)
		return (pointer);
	ft_bzero(pointer, size * nitems);
	return (pointer);
}
