/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:37:55 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/22 14:56:45 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//s1 == dest, s2 = src

#include <stdio.h>
#include <string.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int index = 0;

	while (s2[index] != '\0')
	{
		s1[index] = s2[index];
		index++;
	}
		s1[index] = '\0';
	
	return (s1);
}
