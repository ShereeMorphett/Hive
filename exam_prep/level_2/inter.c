#include <unistd.h>

/* Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$ */

int appeared_before(char *string, int index)
{
    int hold = index - 1;

    while (hold >= 0)
    {
        if (string[hold] == string[index])
            return (1);
        hold--;
    }
    return (0);
}


int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        write(1, "\n", 1);
        return (0);
    }

    int index = 0;
    char letter;
    int check = 0;

    while (argv[1][check])
    {
        index = 0;
        while (argv[2][index])
        {
            if (argv[1][check] == argv[2][index])
            {
                if (appeared_before(argv[1], check) == 0)
                {
                    letter = argv[1][check];
                    write(1, &letter, 1);
                }
                break;
            }
            index++;
        }
        check++;
    }
    write(1, "\n", 1);
    return (0);
}