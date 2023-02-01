/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:51:27 by smorphet          #+#    #+#             */
/*   Updated: 2023/01/25 08:51:29 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static void	send_bits(int server_pid, char letter)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((letter & (0x01 << bit)) != 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

static void	print_errors(void)
{
	ft_putendl_fd("----INPUT ERROR----", 1);
	ft_putendl_fd("Correct input: ./client PID 'MESSAGE' ", 1);
	exit (EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	int	index;
	int	server_pid;

	index = 0;

	if (argc != 3)
		print_errors();
	else
	{
        server_pid = ft_atoi(argv[1]);
		while (argv[2][index] != '\0')
		{
			send_bits(server_pid, argv[2][index]);
			index++;
		}
	}
	exit (EXIT_SUCCESS);
}
