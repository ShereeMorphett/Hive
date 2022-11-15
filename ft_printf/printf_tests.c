//only allowed!!!  malloc, free, write, va_start, va_arg, va_copy, va_end
//Write a library that contains ft_printf(), a function that will mimic the original printf()
/*• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format. • %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.*/
#include <stdio.h>

#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KWHT  "\x1B[37m"

int main()
{
	int digit = 9;
	int character = 'C';
	double test_dec = 4.52;
	char strings[] = "does it print.";


printf("%s~~~~~~~~~~~~visualising printf bonus flags~~~~~~~~~~~~\n %s", KGRN, KWHT);

printf("% f\n", test_dec);
printf("%.3f\n", test_dec);
printf("%+f\n", test_dec);


printf("%s~~~~~~~~~~~~Testing ft_printf~~~~~~~~~~~~\n %s", KGRN, KWHT);

printf("%s \n-----Testing from libft- character input-----\n %s", KMAG, KWHT);
//ft_printf("%c", 'd');
printf("\n");
//ft_printf("%c", 'H');
printf("\n");
//ft_printf("%c", '?');
printf("\n");
//ft_printf("%c", character);

printf("%s \n-----Testing from printf - character input-----\n %s", KBLU, KWHT);
printf("%c", 'd');
printf("\n");
printf("%c", 'H');
printf("\n");
printf("%c", '?');
printf("\n");
printf("%c", character);
printf("\n");

printf("%s \n-----Testing from libft- string input-----\n %s", KMAG, KWHT);
// ft_printf("%s", string);
printf("\n");
// ft_printf("%s", "This should print");

printf("%s \n-----Testing from printf - string input-----\n %s", KBLU, KWHT);
printf("%s", strings);
printf("\n");
printf("%s", "This should print");


printf("%s \n-----Testing from libft- string input-----\n %s", KMAG, KWHT);
// ft_printf("%%");
printf("\n");

printf("%s \n-----Testing from printf - string input-----\n %s", KBLU, KWHT);
printf("%%");
printf("\n");


return (0);
};