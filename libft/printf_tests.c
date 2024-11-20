#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KWHT  "\x1B[37m"

int main()
{
    int digit = 9;
    int character = 'C';
    char strings[] = "does it print.";
    unsigned int number = 29;
    int hundreds = 349;
    int large = 1569565;
    int small = 1;
    int neg = -154;

	int printed_characters;
printf("%s~~~~~~~~~~~~Testing ft_printf~~~~~~~~~~~~%s\n", KGRN, KWHT);


printf("%s \n-----Testing from libft- %%d decimal-----%s\n", KMAG, KWHT);
printed_characters = ft_printf("%d", number);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%d", hundreds);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%d", neg);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%d", small);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%d", large);
printf("\n%i" , printed_characters); 

printf("%s \n-----Testing from printf - %%d Decimal-----%s\n", KBLU, KWHT);
printed_characters = printf("%i", number);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%i", hundreds);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%i", neg);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%i", small);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%i", large);
printf("\n%i" , printed_characters); 

printf("%s \n-----Testing from libft- %%i integer-----%s\n", KMAG, KWHT);
printed_characters = ft_printf("%i", number);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%i", hundreds);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%i", neg);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%i", small);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%i", large);
printf("\n%i" , printed_characters); 

printf("%s \n-----Testing from printf - %%i integer-----%s\n", KBLU, KWHT);
printed_characters = printf("%d", number);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%d", hundreds);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%d", neg);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%d", small);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%d", large);
printf("\n%i" , printed_characters); 


    // Testing %c (character)
    printf("%s\n-----Testing ft_printf - Character Input-----%s\n", KMAG, KWHT);
    printed_characters = ft_printf("%c", 'd');
    printf("\n%d\n", printed_characters);

    printed_characters = ft_printf("%c", character);
    printf("\n%d\n", printed_characters);

    // Testing %c (character)
    printf("%s\n-----Testing printf - Character Input-----%s\n", KMAG, KWHT);
    printed_characters = printf("%c", 'd');
    printf("\n%d\n", printed_characters);

    printed_characters = printf("%c", character);
    printf("\n%d\n", printed_characters);


    // Testing %s (string)
    printf("%s\n-----Testing ft_printf - String Input-----%s\n", KMAG, KWHT);
    printed_characters = ft_printf("%s", strings);
    printf("\n%d\n", printed_characters);

    printed_characters = ft_printf("%s", "This should print");
    printf("\n%d\n", printed_characters);

    printed_characters = ft_printf("NULL %s NULL", "(null)");
    printf("\n%d\n", printed_characters);


    // Testing %s (string)
    printf("%s\n-----Testing printf - String Input-----%s\n", KMAG, KWHT);
    printed_characters = printf("%s", strings);
    printf("\n%d\n", printed_characters);

    printed_characters = printf("%s", "This should print");
    printf("\n%d\n", printed_characters);

    printed_characters = printf("NULL %s NULL", "(null)");
    printf("\n%d\n", printed_characters);



    // Testing %% (percent sign)
    printf("%s\n-----Testing ft_printf - Percent Sign-----%s\n", KMAG, KWHT);
    printed_characters = ft_printf("%%");
    printf("\n%d\n", printed_characters);



    // Testing %p (pointer)
    printf("%s\n-----Testing ft_printf - Pointer-----%s\n", KMAG, KWHT);
    int ab = 10;
    int *bc = &ab;
    printed_characters = ft_printf("%p", bc);
    printf("\n%d\n", printed_characters);

	    // Testing %p (pointer)
    printf("%s\n-----Testing printf - Pointer-----%s\n", KMAG, KWHT);
    int a = 10;
    int *b = &a;
    printed_characters = printf("%p", b);
    printf("\n%d\n", printed_characters);

    // Testing %X and %x (hexadecimal, uppercase and lowercase)
    printf("%s\n-----Testing ft_printf - Uppercase Hexadecimal-----%s\n", KMAG, KWHT);
    printed_characters = ft_printf("%X", digit);
    printf("\n%d\n", printed_characters);


    // Testing %X and %x (hexadecimal, uppercase and lowercase)
    printf("%s\n-----Testing printf - Uppercase Hexadecimal-----%s\n", KMAG, KWHT);
    printed_characters = printf("%X", digit);
    printf("\n%d\n", printed_characters);


    printf("%s\n-----Testing ft_printf - Lowercase Hexadecimal-----%s\n", KMAG, KWHT);
    printed_characters = ft_printf("%x", digit);
    printf("\n%d\n", printed_characters);

    printf("%s\n-----Testing printf - Lowercase Hexadecimal-----%s\n", KMAG, KWHT);
    printed_characters = printf("%x", digit);
    printf("\n%d\n", printed_characters);

    // Testing %u (unsigned integer)
    printf("%s\n-----Testing ft_printf - Unsigned Decimal Base 10-----%s\n", KMAG, KWHT);
    printed_characters = ft_printf("%u", number);
    printf("\n%d\n", printed_characters);

    printed_characters = ft_printf("%u", -1); // Handle unsigned properly
    printf("\n%d\n", printed_characters);

    // Testing multiple format specifiers in a single call
    printf("%s\n-----Testing ft_printf - Multiple Format Specifiers-----%s\n", KMAG, KWHT);
    printed_characters = ft_printf("Unsigned: %u, Int: %d, Char: %c, String: %s, Hex: %x, Percent: %%", number, digit, character, strings, digit);
    printf("\n%d\n", printed_characters);

	    // Testing multiple format specifiers in a single call
    printf("%s\n-----Testing printf - Multiple Format Specifiers-----%s\n", KMAG, KWHT);
    printed_characters = printf("Unsigned: %u, Int: %d, Char: %c, String: %s, Hex: %x, Percent: %%", number, digit, character, strings, digit);
    printf("\n%d\n", printed_characters);

    return 0;
}
