/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:12:05 by smorphet          #+#    #+#             */
/*   Updated: 2022/07/14 11:10:19 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 4096

void	ft_display_file(int file_des)
{
	char	buffer[BUF_SIZE + 1];

	while (read(file_des, buffer, 1))
	{
		write(1, buffer, 1);
	}
	if (close(file_des) == -1)
	{
		write(2, "close() failed\n", 17);
	}
}

int	main(int argc, char **argv)
{
	char	file_des;

	file_des = *argv[0];
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		file_des = open(argv[1], O_RDONLY);
		if (file_des == -1)
			write(2, "Cannot read file.\n", 18);
		else
			ft_display_file(file_des);
	}
}
