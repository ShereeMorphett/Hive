#include "minitalk.h"

void print_errors()
{
    ft_putendl_fd("ERROR MESSAGES WILL BE HERE SOME DAY", 1);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
        print_errors();
    
    ft_putendl_fd(argv[2], 1);
    
    return(0);
}