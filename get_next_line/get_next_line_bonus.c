/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:20:42 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/14 17:20:46 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_line(char *save)
{
	int		index;
	char	*search;

	index = 0;
	if (!save[index])
		return (NULL);
	while (save[index] && save[index] != '\n')
		index++;
	search = (char *)malloc(sizeof(char) * (index + 2));
	if (!search)
		return (NULL);
	index = 0;
	while (save[index] && save[index] != '\n')
	{
		search[index] = save[index];
		index++;
	}
	if (save[index] == '\n')
	{
		search[index] = save[index];
		index++;
	}
	search[index] = '\0';
	return (search);
}

char	*save_line(char *holder)
{
	int		index;
	int		line_index;
	char	*line;
	
	index = 0;
	while (holder[index] && holder[index] != '\n')
		index++;
	if (!holder[index])
	{
		free(holder);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(holder) - index + 1));
	if (!line)
		return (NULL);
	index++;
	line_index = 0;
	while (holder[index])
		line[line_index++] = holder[index++];
	line[line_index] = '\0';
	free(holder);
	return (line);
}

char	*read_file(int fd, char *holder)
{
	char	*buff;
	int		read_char;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_char = 1;
	while (!ft_strchr(holder, '\n') && read_char!= 0)
	{
		read_char = read(fd, buff, BUFFER_SIZE);
		if (read_char  == -1)
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
	static char	*holder[200];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	holder[fd] = read_file(fd, holder[fd]);
	if (holder[fd] == NULL)
		return (0);
	line = find_line(holder[fd]);
	holder[fd] = save_line(holder[fd]);
	return (line);
}