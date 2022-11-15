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
#include "get_next_line_bonus.h"

static char	*find_line(char *holder)
{
	int		index;
	char	*search;

	index = 0;
	if (!holder[index])
		return (NULL);
	while (holder[index] && holder[index] != '\n')
		index++;
	search = (char *)malloc(sizeof(char) * (index + 2));
	if (!search)
		return (NULL);
	index = 0;
	while (holder[index] && holder[index] != '\n')
	{
		search[index] = holder[index];
		index++;
	}
	if (holder[index] == '\n')
	{
		search[index] = holder[index];
		index++;
	}
	search[index] = '\0';
	return (search);
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
	new_holder= (char *)malloc(sizeof(char) * (ft_strlen(holder) - index + 1));
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

char *get_next_line(int fd)
{
 char *line;
 static char *holder[1000];

 if (fd < 0 || BUFFER_SIZE <= 0 || fd > 999)
  return (NULL);
 holder[fd] =	read_file(fd, holder[fd]);
 if (!holder[fd])
  return (NULL);
 line = find_line(holder[fd]);
 holder[fd] = update_holder(holder[fd]);
 return (line);
}