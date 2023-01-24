#include "minitalk.h"

int running = 1;

static void print_pid(void)
{
	char	*server_pid;

	server_pid = ft_itoa(getpid());
	ft_putstr_fd("server pid: ", 1);
	ft_putendl_fd(server_pid, 1);
	free(server_pid);
}

void	signal_handle(int signal)
{
	static int	bit;
	static int	letter;
	
	if (signal == SIGINT)
	{
		ft_putendl_fd("Exiting program", 1);	
		running = 0;
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

int main(int argc, char *argv[])
{
		if (argc != 1 && argv[0] != NULL)
	{
		ft_putendl_fd("----INPUT ERROR----", 1);
		ft_putendl_fd("Correct input: ./server", 1);
		return (0);
	}
    print_pid();
	ft_putendl_fd("Waiting on client program...", 1);
	while (running)
	{
		signal(SIGUSR1, signal_handle);
		signal(SIGUSR2, signal_handle);
		pause ();
	}
    exit (EXIT_SUCCESS);
}