/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:54:39 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/06 12:11:49 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	index;
	int	word;

	index = 0;
	word = 0;
	while (s && s[index])
	{
		if (s[index] != c)
		{
			word++;
			while (s[index] != c && s[index])
				index++;
		}
		else
			index++;
	}
	return (word);
}

static int	word_length(char const *str, char c, int index)
{
	int	size;

	size = 0;
	while (str[index] != c && str[index])
	{
		size++;
		index++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		word;
	char	**str_array;
	int		out_index;

	index = 0;
	out_index = -1;
	word = count_words(s, c);
	str_array = (char **)malloc((word + 1) * sizeof(char *));
	if (!str_array)
		return (NULL);
	while (++out_index < word)
	{
		while (s[index] == c)
			index++;
		str_array[out_index] = ft_substr(s, index, word_length(s, c, index));
		if (!str_array[out_index])
		{
			free(str_array);
			return (NULL);
		}
		index += word_length(s, c, index);
	}
	str_array[out_index] = 0;
	return (str_array);
}
