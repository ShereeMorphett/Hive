/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:17:49 by smorphet          #+#    #+#             */
/*   Updated: 2022/06/30 14:18:41 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	ascii_letter;
	int		letter;

	letter = 97;
	while (letter <= 122)
	{
		ascii_letter = letter;
		ft_putchar(ascii_letter);
		letter++;
	}
}
