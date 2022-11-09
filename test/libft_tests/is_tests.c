#include "libft.h"
#include <stdio.h>
#include <ctype.h>

#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KWHT  "\x1B[37m"



int main(void)
{
    printf("%s Testing ft_isalpha\n %s", KGRN, KWHT);

    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);
    
    if (ft_isalpha('A') != 0)
         printf("It's an alphabet.\n");
    else
         printf("It's not an alphabet.\n");
    
    if (ft_isalpha('d') != 0)
        printf("It's an alphabet.\n");
    else
        printf("It's not an alphabet.\n");

    if (ft_isalpha('0') != 0)
        printf("It's an alphabet.\n");
    else
        printf("It's not an alphabet.\n");
    
    if (ft_isalpha('+') != 0)
        printf("It's an alphabet.\n");
    else
        printf("It's not an alphabet.\n");


    printf("%s\n-----Testing from original-----\n%s", KBLU, KWHT);

    if (isalpha('A') != 0)
         printf("It's an alphabet.\n");
    else
         printf("It's not an alphabet.\n");
    
    if (isalpha('d') != 0)
        printf("It's an alphabet.\n");
    else
        printf("It's not an alphabet.\n");

    if (isalpha('0') != 0)
        printf("It's an alphabet.\n");
    else
        printf("It's not an alphabet.\n");
    
    if (isalpha('+') != 0)
        printf("It's an alphabet.\n");
    else
        printf("It's not an alphabet.\n");
    
 
    printf("\n%sTesting ft_isdigit\n", KGRN);
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);
    
    if (ft_isdigit('9') != 0)
        printf("It's a digit.\n");
    else
        printf("It's not a digit.\n");
    
    if (ft_isdigit('4') != 0)
        printf("It's a digit.\n");
    else
        printf("It's not a digit.\n");
    
    if (ft_isdigit('0') != 0)
        printf("It's a digit.\n");
    else
        printf("It's not a digit.\n");
    
    if (ft_isdigit('+') != 0)
        printf("It's a digit.\n");
    else
        printf("It's not a digit.\n");

    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);

    if (isdigit('9') != 0)
        printf("It's a digit.\n");
    else
        printf("It's not a digit.\n");
    
    if (isdigit('4') != 0)
        printf("It's a digit.\n");
    else
        printf("It's not a digit.\n");
    
    if (isdigit('0') != 0)
        printf("It's a digit.\n");
    else
        printf("It's not a digit.\n");
    
    if (isdigit('+') != 0)
        printf("It's a digit.\n");
    else
        printf("It's not a digit.\n");


    printf("\n %s Testing ft_isalnum\n", KGRN);

    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);

    if (ft_isalnum('9') != 0)
    printf("It is alpha numeric.\n");
    else        
    printf("It's not a alpha numeric.\n");
    
    if (ft_isalnum('4') != 0)
    printf("It is alpha numeric.\n");
    else
        printf("It's not a alpha numeric.\n");
    if (ft_isalnum('A') != 0)    
    printf("It is alpha numeric.\n");
    else
        printf("It's not a alpha numeric.\n");    
    if (ft_isalnum('d') != 0)
    printf("It is alpha numeric.\n");
    else
        printf("It's not a alpha numeric.\n");
    if (ft_isalnum('+') != 0)
    printf("It is alpha numeric.\n");
    else
        printf("It's not a alpha numeric.\n");

    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);

        if (isalnum('9') != 0)
    printf("It is alpha numeric.\n");
    else        
    printf("It's not a alpha numeric.\n");
    
    if (isalnum('4') != 0)
    printf("It is alpha numeric.\n");
    else
        printf("It's not a alpha numeric.\n");
    if (isalnum('A') != 0)    
    printf("It is alpha numeric.\n");
    else
        printf("It's not a alpha numeric.\n");    
    if (isalnum('d') != 0)
    printf("It is alpha numeric.\n");
    else
        printf("It's not a alpha numeric.\n");
    if (isalnum('+') != 0)
    printf("It is alpha numeric.\n");
    else
        printf("It's not a alpha numeric.\n");

    printf("\n%sTesting ft_isascii\n", KGRN);
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);

    if (ft_isascii('\x80') != 0) // ascii euro sign
    printf("It is on the ASCII table.\n");
    else
        printf("It's not on ASCII table.\n");    
    if (ft_isascii('#') != 0)
        printf("It is on the ASCII table.\n");
    else
        printf("It's not on ASCII table.\n");
    if (ft_isascii('}') != 0)
        printf("It is on the ASCII table.\n");
    else
        printf("It's not on ASCII table.\n");
    if (ft_isascii('?') != 0)
        printf("It is on the ASCII table.\n");
    else
        printf("It's not on ASCII table.\n");
    if (ft_isascii(' ') != 0)
        printf("It is on the ASCII table.\n");
    else
        printf("It's not on ASCII table.\n");

    
    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);

        if (isascii('\x80') != 0) // ascii euro sign
    printf("It is on the ASCII table.\n");
    else
        printf("It's not on ASCII table.\n");    
    if (isascii('#') != 0)
        printf("It is on the ASCII table.\n");
    else
        printf("It's not on ASCII table.\n");
    if (isascii('}') != 0)
        printf("It is on the ASCII table.\n");
    else
        printf("It's not on ASCII table.\n");
    if (isascii('?') != 0)
        printf("It is on the ASCII table.\n");
    else
        printf("It's not on ASCII table.\n");
    if (isascii(' ') != 0)
        printf("It is on the ASCII table.\n");
    else
        printf("It's not on ASCII table.\n");
    

    printf("\n%sTesting ft_isprint\n", KGRN);
    printf("%s\n-----Testing from libft-----\n%s", KMAG, KWHT);

    if (ft_isprint(' ') != 0)
        printf("It is a printable character.\n");
    else
        printf("It's not a printable character.\n");
    if (ft_isprint('A') != 0)
        printf("It is a printable character.\n");
    else
        printf("It's not a printable character.\n");
    if (ft_isprint('o') != 0)
        printf("It is a printable character.\n");
    else
        printf("It's not a printable character.\n");
    if (ft_isprint('3') != 0)
        printf("It is a printable character.\n");
    else
        printf("It's not a printable character.\n");

    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);

    if (isprint(' ') != 0)
        printf("It is a printable character.\n");
    else
        printf("It's not a printable character.\n");
    if (isprint('A') != 0)
        printf("It is a printable character.\n");
    else
        printf("It's not a printable character.\n");
    if (isprint('o') != 0)
        printf("It is a printable character.\n");
    else
        printf("It's not a printable character.\n");
    if (isprint('3') != 0)
        printf("It is a printable character.\n");
    else
        printf("It's not a printable character.\n");
    return (0);
}