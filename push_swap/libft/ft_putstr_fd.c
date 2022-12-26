/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:00:40 by smorphet          #+#    #+#             */
/*   Updated: 2022/10/25 15:00:55 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	index;

	index = 0;
	if (str)
	{
		while (str[index] != '\0')
		{
			ft_putchar_fd(str[index], fd);
			index = index + 1;
		}
	}
}
