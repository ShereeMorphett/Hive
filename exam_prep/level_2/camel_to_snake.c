#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$ 
*/

static void put_string(char *string)
{
    int index;
    
    index = 0;
    while (string[index])
    {
        write(1, &string[index], 1);
        index++;
    }
}

int main(int argc, char *argv[])
{
    int index;
    int upper_count;
    int cpy_index;
    char *string;
    char letter;

    cpy_index = 0;
    index = 0;

    if (argc != 2)
        write(1, "\n", 1);
    while (argv[1][index])
    {
        if (argv[1][index] >= 65 && argv[1][index] <= 90)
            upper_count++;
        index++;
    }
    string = malloc(sizeof(char) * index + upper_count + 1);
    index = 0;
        while (argv[1][index])
    {
        if (argv[1][index] >= 65 && argv[1][index] <= 90)
        {
            string[cpy_index++] = '_';
            string[cpy_index++] = argv[1][index] + 32;
        }
         else
         {
            string[cpy_index++] = argv[1][index];
         }
         index++;
    }
    string[cpy_index] = '\0';
    put_string(string);
    write(1, "\n", 1);
    free(string);
}