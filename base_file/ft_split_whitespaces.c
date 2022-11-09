
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:21:04 by smorphet          #+#    #+#             */
/*   Updated: 2022/07/07 17:55:43 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	index;
	
	index = 0;
	while (*s++)
		index++;
	return (index);
}

char **split_whitespace(char *str)
{
    if (str == ' ' || str == '\t' || str == '\n')
        return (1);
    return (0);
}

int    word_count(const char *str)
{
    int    size;

    size = 0;
    while (*str)
    {
        while (!split_whitespace(*str) && *str)
            ++str;
            ++size;
        while (split_whitespace(*str) && *str)
            ++str;
    }
    return (size);
}


int    word_length(const char *str)
{
    int size;

    while (*str)
    {
        if (!split_whitespace(*str))
            break ;
        ++str;
    }
    size = 0;
    while (*str)
    {
        if (split_whitespace(*str))
            break ;
        ++size;
        ++str;
    }
    return (size - 1);
}

char        **ft_string_whitespaces(const char *str)
{
    char    **word;
    int number_of_words;
    int size;
    int index;
    
    size = 0;
    index = 0;
    
    while (split_whitespace(*str))
        ++str;
    
    number_of_words = word_count(str);
    
    word = (char **)malloc(sizeof(char *) * (number_of_words + 1));
    ft_strncpy(word[index], str, size);
    str += size;
    
    
    while (split_whitespace(*str))
    {
        ++str;
        ++index;
    }
    
    word[index] = 0;
    
    return (word);
    
}


int main(void)
{
    char string[19] = "Things   go	here.\n";
	char wrd_array;
	
	wrd_array = split_whitespaces(string);
    
    printf("%c", wrd_array);

	return (0);
}
