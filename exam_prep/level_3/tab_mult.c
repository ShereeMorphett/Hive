/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:33:22 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/20 13:16:32 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
/* Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$> */



void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

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

int ft_atoi(char *multiple)
{
	int multiplier;
	int index = 0;

	while(multiple[index] != '\0' && (multiple[index] >= '0' && multiple[index] <= '9'))
	{	
		multiplier = (multiplier * 10 ) + (multiple[index] - '0');
		index++;
	}
	return (multiplier);

}


int			main(int argc, char **argv)
{
	int	n;
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	n = ft_atoi(argv[1]);
	if (n <= 0 || n * 9 <= 0)
		return (1);
	i = 1;
	while (i <= 9)
	{
		ft_putnbr_fd(i, 1);
		write(1, " x ", 3);
		ft_putnbr_fd(n, 1);
		write(1, " = ", 3);
		ft_putnbr_fd(i * n, 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
