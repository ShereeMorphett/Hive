/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:57:40 by smorphet          #+#    #+#             */
/*   Updated: 2022/06/30 06:47:55 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char	ascii_letter;
	int		digit;

	digit = 48;
	while (digit <= 57)
	{
		ascii_letter = digit;
		ft_putchar(ascii_letter);
		digit++;
	}
}
