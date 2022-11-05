/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:11:35 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/01 10:11:37 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>


char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	h_index;
	int				n_index;

	n_index = 0;
	h_index = 0;


	if (!*needle)
		return ((char *)haystack);  
    if ((len == 0) || *haystack == '\0')
        return (NULL);
	while (haystack[h_index])
	{
		n_index = 0;
		while (haystack[h_index] == needle[n_index] && haystack[h_index] && h_index < len)
		{
			h_index++;
			n_index++;
		}
		if (!needle[n_index])
			return ((char *)&haystack[h_index - n_index]);
		h_index = (h_index - n_index) + 1;
	}
	return (NULL);
}