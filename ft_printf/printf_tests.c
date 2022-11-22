//only allowed!!!  malloc, free, write, va_start, va_arg, va_copy, va_end
//Write a library that contains ft_printf(), a function that will mimic the original printf()
/*• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format. 
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.*/
#include <stdio.h>

#include "ft_printf.h"

#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KWHT  "\x1B[37m"

int main()
{
	int digit = 9;
	int character = 'C';
	int test_dec = 4;
	char strings[] = "does it print.";
	unsigned int number = 29;
	int	hundreds = 349;
	int	thousands = 2542;
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


printf("%s \n-----Testing from libft- character input-----%s\n", KMAG, KWHT);
printed_characters = ft_printf("%c", 'd');
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%c", 'H');
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%c", '?');
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%c", character);
printf("\n%i" , printed_characters); 

printf("%s \n-----Testing from printf - character input-----%s\n", KBLU, KWHT);
printed_characters = printf("%c", 'd');
printf("\n%i" , printed_characters); 
printf("\n\n");
printf("%c", 'H');
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%c", '?');
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%c", character);
printf("\n%i" , printed_characters); 
printf("\n\n");

printf("%s \n-----Testing from libft- string input-----%s\n", KMAG, KWHT);

printed_characters = ft_printf("%s", strings);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%s", "This should print");
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf(" NULL %s NULL ", NULL);
printf("\n%i" , printed_characters); 


printf("%s \n-----Testing from printf - string input-----%s\n", KBLU, KWHT);
printed_characters = printf("%s", strings);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%s", "This should print");
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf(" NULL %s NULL ", NULL);
printf("\n%i" , printed_characters); 

printf("%s \n-----Testing from libft- printing percentage sign-----%s\n", KMAG, KWHT);
printed_characters = ft_printf("%%");
printf("\n%i" , printed_characters); 
printf("\n\n");

printf("%s \n-----Testing from printf - printing percentage sign-----%s\n", KBLU, KWHT);
printed_characters = printf("%%");
printf("\n%i" , printed_characters); 
printf("\n\n");

printf("%s \n-----Testing from libft- printing pointer-----%s\n", KMAG, KWHT);
int a = 10; 
int *b = &a; 
printed_characters = ft_printf("%p", b); 
printf("\n%i" , printed_characters); 
printf("\n\n");

printf("%s \n-----Testing from printf - printing pointer-----%s\n", KBLU, KWHT);

printed_characters = printf("%p\n", b); 
printf("\n%i" , printed_characters);
printf("\n\n");

printf("%s \n-----Testing from libft- uppercase hexadecimal-----%s\n", KMAG, KWHT);


printed_characters = ft_printf("%X",number); 
printf("\n%i" , printed_characters); 

printf("\n\n");
printed_characters = ft_printf("%X",digit); 
printf("\n%i" , printed_characters); 



printf("%s \n-----Testing from printf - uppercase hexadecimal-----%s\n", KBLU, KWHT);

printed_characters = printf("%X", number);
printf("\n%i" , printed_characters); 

printf("\n\n");
printf("%X", digit);
printf("\n%i" , printed_characters); 


printf("%s \n-----Testing from libft- lowercase hexadecimal-----%s\n", KMAG, KWHT);
 
printed_characters = ft_printf("%x", number); 
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%x\n", digit);
printf("\n%i" , printed_characters); 

printf("%s \n-----Testing from printf - lowercase hexadecimal-----%s\n", KBLU, KWHT);

printed_characters = printf("%x", number); 
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%x", digit);
printf("\n%i" , printed_characters); 

printf("%s \n-----Testing from libft- Unsigned decimal base 10-----%s\n", KMAG, KWHT);

printed_characters = ft_printf("%u", number); 
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%u", digit);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%u", -1);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%u", -9);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%u", 0);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("%u", -200);
printf("\n%i" , printed_characters);


printf("%s \n-----Testing from printf - Unsigned decimal base 10-----%s\n", KBLU, KWHT);

printed_characters = printf("%u", number); 
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%u", digit);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%u", -1);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%u", -9);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%u", 0);
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("%u", -200);
printf("\n%i" , printed_characters);


printf("%s \n-----Testing from libft- multiple formatters-----%s\n", KMAG, KWHT);

printed_characters = ft_printf("this has an unsigned number %u and an int %d", number, digit); 
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = ft_printf("this has all of the arguments %d,  %i,   %c,   %s,  %%,  %p, %x, %X", digit, number, character, strings, b, digit, digit);
printf("\n%i" , printed_characters); 

printf("%s \n-----Testing from printf - Umultiple formatters-----%s\n", KBLU, KWHT);

printed_characters = printf("this has an unsigned number %u and an int %d", number, digit); 
printf("\n%i" , printed_characters); 
printf("\n\n");
printed_characters = printf("this has all of the arguments %d,  %i,   %c,   %s,  %%,  %p, %x, %X", digit, number, character, strings, b, digit, digit);
printf("\n%i" , printed_characters); 

return (0);
};