/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:36:01 by smorphet          #+#    #+#             */
/*   Updated: 2022/10/25 15:00:13 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	storage;

	storage = n;
	if (storage < 0)
	{
		ft_putchar_fd('-', fd);
		storage = -storage;
	}
	if (storage / 10)
		ft_putnbr_fd(storage / 10, fd);
	ft_putchar_fd(storage % 10 + '0', fd);
}
