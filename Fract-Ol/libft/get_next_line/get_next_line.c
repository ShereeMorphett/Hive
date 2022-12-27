/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:55:52 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/15 12:09:04 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*find_line(char *holder)
{
	int		len;
	char	*line;

	len = 0;
	if (!holder[len])
		return (NULL);
	while (holder[len] && holder[len] != '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	len = 0;
	while (holder[len] && holder[len] != '\n')
	{
		line[len] = holder[len];
		len++;
	}
	if (holder[len] == '\n')
	{
		line[len] = holder[len];
		len++;
	}
	line[len] = '\0';
	return (line);
}

static char	*update_holder(char *holder)
{
	int		index;
	int		new_index;
	char	*new_holder;

	index = 0;
	while (holder[index] && holder[index] != '\n')
		index++;
	if (!holder[index])
	{
		free(holder);
		return (NULL);
	}
	new_holder = (char *)malloc(sizeof(char) * (ft_strlen(holder) - index + 1));
	if (!new_holder)
		return (NULL);
	index++;
	new_index = 0;
	while (holder[index])
		new_holder[new_index++] = holder[index++];
	new_holder[new_index] = '\0';
	free(holder);
	return (new_holder);
}

static char	*read_file(int fd, char *holder)
{
	char	*buff;
	int		read_char;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_char = 1;
	while (!ft_strchr(holder, '\n') && read_char != 0)
	{
		read_char = read(fd, buff, BUFFER_SIZE);
		if (read_char == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_char] = '\0';
		holder = gnl_strjoin(holder, buff);
	}
	free(buff);
	return (holder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*holder[1000];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 999)
		return (NULL);
	holder[fd] = read_file(fd, holder[fd]);
	if (!holder[fd])
		return (NULL);
	line = find_line(holder[fd]);
	holder[fd] = update_holder(holder[fd]);
	return (line);
}
