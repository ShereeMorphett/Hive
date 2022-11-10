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
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

#define BUF_SIZE 4096

char *get_next_line(int fd)
{	
	
	int ret;
	static char buf[BUF_SIZE + 1];
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';

	printf("%s", buf);

	return (buf);
}










// BELOW PRINTS THE FULL FILE (FOR WHEN FUTURE SHEREE BREAKS IT)
/* char *get_next_line(int fd)
{	
	
	int ret;
	static char buf[BUF_SIZE + 1];
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';

	printf("%s", buf);

	return (buf);
} */