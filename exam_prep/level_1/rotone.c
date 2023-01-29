#include <unistd.h>
/*Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>*/

int main(int argc, char* argv[])
{
    int index;
    char letter;
    
    index = 0;
    if (argc != 2)
       write(1, "\n", 1);
    if (argv[1] == NULL)
        write(1, "\n", 1);
    while (argv[1][index])
    { 
        if ((argv[1][index] >= 65 && argv[1][index] <= 90) || (argv[1][index] >= 97 && argv[1][index] <= 122))
        {
            if (argv[1][index] >= 65 && argv[1][index] <= 90)
        {
            if (argv[1][index] == 90)
                write(1, "A", 1);
            else
            {
                letter = argv[1][index] + 1;
                write(1, &letter, 1);
            }
        }
            else if (argv[1][index] >= 97 && argv[1][index] <= 122)
        {
            if (argv[1][index] == 122)
                write(1, "a", 1);
            else
            {
                letter = argv[1][index] + 1;
                write(1, &letter, 1);
            }
        }
    }
        else
            write(1, &argv[1][index], 1);
        index++;
}
    write(1, "\n", 1);
    return (0);
}