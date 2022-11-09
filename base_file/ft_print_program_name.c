/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:19:23 by smorphet          #+#    #+#             */
/*   Updated: 2022/07/06 16:09:57 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	index;

	index = 0;
	if (argc)
	{
		while (argv[0][index] != '\0')
		{
			ft_putchar(argv[0][index]);
			index++;
		}
		ft_putchar('\n');
		return (0);
	}
}
