/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:17:35 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/06 11:37:54 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
/* Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject); 
    
The strcspn() function spans the initial part of the null-terminated string s as long as the characters from s do not occur in the null-terminated string charset
(it spans the complement of charset). 
In other words, it computes the string array index of the first character of s which is also in charset, else the index of the first null character.*/

size_t	ft_strcspn(const char *s, const char *reject)
{
	
	size_t index = 0;
	int char_set = 0;
	
	while (s[index] != '0')
	{	
		while (s[index] != reject[char_set] && reject[char_set] != '\0')
		{
			char_set++;
		}
		if (s[index] == reject[char_set])
		{
			return (index);
		}

		char_set = 0;
		index++;
	}

			return (index);
}

int main(void)
{
	printf("mine: %zu \n", ft_strcspn("", "" ) );
	printf("og: %zu \n", strcspn("","" ) );




}
