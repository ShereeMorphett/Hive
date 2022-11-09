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
	int	i;
	
	i = 0;
	while (*s++)
		i++;
	return (i);
}

char **split_whitespace(char *str)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    return (0);

}

int    word_counter(const char *str)
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
    int        size;

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



int main(void)
{
	char string = "Things   go	here. Things thats	have words and whitespace \n";
	char wrd_array;
	
	wrd_array = ft_split_whitespaces(string);


	printf("%s", string);
	
	while (++wrd_array != '\0')
		printf("%s", wrd_array);

	return (0);
}
