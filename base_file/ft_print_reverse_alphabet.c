/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:47:37 by smorphet          #+#    #+#             */
/*   Updated: 2022/06/30 15:47:38 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	char	ascii_letter;
	int		letter;

	letter = 122;
	while (letter >= 97)
	{
		ascii_letter = letter;
		ft_putchar(ascii_letter);
		letter--;
	}
}
