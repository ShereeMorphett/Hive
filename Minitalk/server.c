#include "minitalk.h"

static void print_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	ft_putstr_fd("pid: ", 1);
	ft_putendl_fd(pid, 1);
	free(pid);
}

int main(void)
{
    print_pid();
    return(0);
}