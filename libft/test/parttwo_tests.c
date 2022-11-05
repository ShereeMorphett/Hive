#include "libft.h"
#include <stdio.h>
#include <string.h>
#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KWHT  "\x1B[37m"


void    striteri_myfunc(unsigned int i, char *str_at_ft_striteri)
{
        ft_putchar_fd(*str_at_ft_striteri, 1);
        printf("\n");
}

// strmapi_myfunc is just ft_toupper with a pretend int.
char    strmapi_myfunc(unsigned int i, char character)
{

    printf("%d,  %c", i, character);
    if (character > 122 || character < 97)
            return (character);
    else
        return  (character - 32);
    

    return (i);
}

int main(void)
{
    printf("%s \n\n\n==========%s PART 2%s ==========%s \n", KBLU, KMAG, KBLU, KWHT);
    
    printf("\n%s Testing ft_strjoin %s\n", KMAG, KWHT);

    printf("this should print - does this work \n");
    char const s1[11] = "does this ";
    char const s2[10] = "work\n";
    
    char const *newstring = ft_strjoin(s1, s2);
    printf("%s\n", newstring);
    

    printf("\n%sTesting ft_striteri%s\n", KMAG, KWHT);
     char  *stuff;
     stuff = "work\n";
     ft_striteri(stuff, striteri_myfunc);
     printf("%s\n", stuff);


    printf("\n%sTesting ft_strmapi%s \n", KMAG, KWHT);
    printf("Before ft_strmapi: %s\n", stuff);
     ft_strmapi(stuff, strmapi_myfunc);
     printf("After ft_strmapi: %s\n", stuff);

    printf("%sTesting ft_substr%s\n", KMAG, KWHT);
    char const string[18] = "make a sub string\n";
    printf("%s", string);
    char *substring = ft_substr(string, 2, 10);
    printf("%s\n", substring);

    
    
    printf("\n%sTesting ft_strtrim%s\n", KMAG, KWHT);
    char const *string_trim = "abc stuff abc";
    char const *set = "abc ";
    char *new_string = ft_strtrim(string_trim, set);

   printf("%s \n", string_trim);
   printf("%s \n", new_string);
    
    printf("\n%sTesting ft_putchr_fd%s\n", KMAG, KWHT);
           
     ft_putchar_fd('T', 1);
     ft_putchar_fd('E', 1);
     ft_putchar_fd('S', 1);
     ft_putchar_fd('T', 1);
     ft_putchar_fd('\n', 1);
    
    printf("\n%sTesting ft_putnbr_fd%s\n", KMAG, KWHT);
    ft_putnbr_fd(1, 1);
    ft_putnbr_fd(2, 1);
    ft_putnbr_fd(3, 1);
    ft_putchar_fd('\n', 1);
    
    printf("\n%sTesting ft_putstr_fd%s\n", KMAG, KWHT);
    char string1[8] = "Testing";
    ft_putstr_fd(string1, 1);
    ft_putchar_fd('\n', 1);
    printf("\nEnd of tests\n");

    printf("\n%sTesting ft_putstr_fd%s\n", KMAG, KWHT);
    ft_putendl_fd(string1, 1);
    printf("$$$$$$$$$");
    printf("\nEnd of tests\n");
    
    return (0);
}
