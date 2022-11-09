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

// read(int fd, char *baf, int count)

char *get_next_line(int fd)
{	
	int buffer = 42;
	char buff[buffer +1];
	int ret;

	while (ret = read(fd, char *baf, int count))
	{
		buff[ret]= '\0';

	}

}