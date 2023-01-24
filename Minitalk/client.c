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

static void print_errors()
{
		ft_putendl_fd("----INPUT ERROR----", 1);
		ft_putendl_fd("Correct input: ./client <PID> <MESSAGE>", 1);
		exit (EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    int index;
    int server_pid;
    
    index = 0;
    server_pid = ft_atoi(argv[1]);
    if (argc != 3)
        print_errors();
    else
	{
		if (!ft_strncmp(argv[2], "EXIT", 5))
			kill(server_pid, SIGINT);
		while (argv[2][index] != '\0')
		{
            send_bits(server_pid, argv[2][index]);
			index++;
		}
		send_bits(server_pid, '\n');
	}
    return(0);
    
}