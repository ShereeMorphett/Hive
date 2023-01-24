#include "minitalk.h"

void print_errors()
{
    ft_putendl_fd("ERROR MESSAGES WILL BE HERE SOME DAY", 1);
}

int main(int argc, char *argv[])
{
    int pid;
    if (argc != 3)
        print_errors();
    
    pid = ft_atoi(argv[1]);
    ft_putendl_fd(argv[2], 1);
    kill(pid, 0); /* kill(pid, int sig);- If sig is zero, kill() performs error checking, but does not send a signal.
                        You can use a sig value of zero to check whether the pid argument is valid. */
    return(0);
    
}