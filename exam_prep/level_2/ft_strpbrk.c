/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:10:01 by smorphet          #+#    #+#             */
/*   Updated: 2023/01/30 13:40:32 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
/*Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2); */


char *ft_strpbrk(const char *s1, const char *s2)
{
	int index = 0;

	if (!*s1 || !*s2)
	   return (0);	

	while (*s1) 
	{
		if (*s1 == s2[index])
			return ((char *) &s1);
		if (s2[index] && *s1 != s2[index])
			index++;
		else
		{
			index = 0;
			s1++;
		}
	}
	return (0);
}



int main()
{
	const char *s1 = "the main thing";
	const char *s2 = " thing";

	printf("%s", ft_strpbrk(s1, s2));
	printf("%s", strpbrk(s1, s2));



	return (0);
}

