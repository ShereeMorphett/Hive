/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:55:52 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/08 10:55:54 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_line(char *holder)
{
	int counter;
	char	*line;

	if (!holder)
		return (NULL);
	while (*holder && *holder != '\n')
		holder++;
		counter++;
	line = (char *)malloc(sizeof(char) * (counter + 2));
	if (!line)
		return (NULL);
	while (holder && *holder != '\n')
	{
		*line++ = *holder++;
	}
	if (*holder == '\n')
	{
		*line++ = *holder++;
	}
	*line = '\0';
	return (line);
}

char	*update_hold(char *holder)
{
	int		count = 0;
	char	*string;

	while (*holder && *holder != '\n')
		holder++;
		count++;
	if (!holder)
	{
		free(holder);
		return (NULL);
	}
	string = (char *)malloc(sizeof(char) * (ft_strlen(holder) + 1 - count));
	if (!string)
		return (NULL);
	count++;
	while (holder)
		*string++ = *holder++;
	*string = '\0';
	free(holder);
	return (string);
}

char	*read_string_to_hold(int fd, char *holder)
{
	int		read_char;
	char	*buffer;
	

	buffer = malloc((BUF_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_char = 1;
	while (!ft_strchr(holder, '\n') && read_char != 0)
	{
		read_char = read(fd, buffer, BUF_SIZE);
		if (read_char == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_char] = '\0';
		holder = ft_strjoin(holder, buffer);
	}
	free(buffer);
	return (holder);
}

char *get_next_line(int fd)
{	
	static char *holder[4096];
	char *returned_line;

	holder[fd] = read_string_to_hold(fd, holder[fd]);
	
	if (BUF_SIZE <= 0 || !holder[fd])
		return (0);

	returned_line = get_next_line(fd);

	holder[fd] = update_hold(holder[fd]);
	return (returned_line);
}