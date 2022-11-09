/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:21:01 by smorphet          #+#    #+#             */
/*   Updated: 2022/06/30 15:49:58 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void    ft_putchar(char c)
	{
    	write(1, &c, 1);
	}


void	ft_print_combn(char h, char t, char u)
{
	char	hundreds;
	char	tens;
	char	units;

	hundreds = '0';
	while (hundreds <= h)
	{
		tens = hundreds + 1;
		while (tens <= t)
		{
			units = tens + 1;
			while (units <= u)
			{
				ft_putchar(hundreds);
				ft_putchar(tens);
				ft_putchar(units);
				if (hundreds != '7')
					write(1, ", ", 2);
				units++;
			}
			tens++;
		}
		hundreds++;
	}
}

int main()
{

	ft_print_combn('2', '3','5');
	return (0);

}