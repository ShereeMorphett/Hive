/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:54:39 by smorphet          #+#    #+#             */
/*   Updated: 2022/10/31 13:54:41 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static int	word_counter(char const *str, char c)
{
	int index;
	int word;

	index = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		while (str[index] == c && str[index])
			index++;
		if (str[index] != c && str[index])
			word++;
		while (str[index] != c && str[index])
			index++;
	}
	return (word);
}

static int	next(char const *str, char c, int index)
{
	if (index == 0 && str[index] != c && str[index])
		return (index);
	while (str[index] != c && str[index])
		index++;
	while (str[index] == c && str[index])
		index++;
	return (index);
}

static int	word_length(char const *str, char c, int i)
{
	int length;

	length = 0;
	while (str[i + length] != c && str[i + length])
		length++;
	return (length);
}

char		**ft_split(char const *str, char c)
{
	char	**holder;
	int		word_count;
	int		str_index;
	int		index;
	int		wrd_ind;

	word_count = word_counter(str, c);
	if (!(holder = (char**)malloc(sizeof(char*) * (word_count + 1))))
		return (NULL);
	index = 0;
	str_index = 0;
	while (index < word_count && str)
	{
		str_index = next(str, c, str_index);
		wrd_ind = 0;
		if (!(holder[word_count] = (char*)malloc(sizeof(char) * word_length(str, c, str_index))))
			return (NULL);

		while (str[str_index] && str[str_index] != c)
			holder[index][wrd_ind] = str[str_index++];
		holder[index++][wrd_ind] = '\0';
	}
	holder[index] = 0;
	return (holder);
}
