/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:51:18 by smorphet          #+#    #+#             */
/*   Updated: 2023/01/25 08:51:21 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static void	print_pid(void)
{
	char	*server_pid;

	server_pid = ft_itoa(getpid());
	ft_putstr_fd("server pid: ", 1);
	ft_putendl_fd(server_pid, 1);
	free(server_pid);
}

static void	signal_process(int signal)
{
	static int	bit;
	static int	letter;

	if (signal == SIGINT)
	{
		ft_putendl_fd("Exiting program", 1);
		exit (EXIT_SUCCESS);
	}
	if (signal == SIGUSR1)
		letter |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(letter, 1);
		bit = 0;
		letter = 0;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 1 && argv[0] != NULL)
	{
		ft_putendl_fd("----INPUT ERROR----", 1);
		ft_putendl_fd("Correct input: ./server", 1);
		exit (EXIT_FAILURE);
	}
	print_pid();
	ft_putendl_fd("Waiting on client program...", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, signal_process);
		signal(SIGUSR2, signal_process);
		pause ();
	}
	exit (EXIT_SUCCESS);
}
