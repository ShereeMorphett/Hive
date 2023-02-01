#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KWHT  "\x1B[37m"
#define EMPTY_STRING  ""

#include <stdlib.h>
#include <stdio.h>

int ft_atoi (const char *str)
{

	long int result = 0;
	int index = 0;
	int sign = 1;
	
	while( str[index] <= 32 || str[index] == 127)
		index++;
	if (str[index] == '+')
	{
		sign = 1;
		index++;
	}
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	while(str[index])
	{	
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	return (result * sign);
}



int main(void)
{
	    //------------FT_ATOI-------------
    printf("\n\033[0;33m ft_atoi tests: \033[0m\n\n");
	
	
	printf("ft:  %d \n", ft_atoi("1234"));
	printf("og:  %d \n", atoi("1234"));

 	// const char *atoi_test = "2";
    // const char *atoi_test1 = "30";
    // const char *atoi_test2 = "-5789";
    // const char *atoi_test3 = "0";
    // const char *atoi_test4 = "-2147483648";
    // const char *atoi_test5 = "2147483647";
	
    //basic tests
    // printf("FT: %i\nsys %i\n", ft_atoi("          -232938"), atoi("          -232938"));
    // printf("\nFT: %i\nsys %i\n", ft_atoi("-          232938"), atoi("-          232938"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("--          232938"), atoi("--          232938"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("++          232938"), atoi("++          232938"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("+          232938"), atoi("+          232938"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("          +232938"), atoi("          +232938"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("1.3f"), atoi("1.3f"));
    printf("\nFT: %i\nsys %i\n", ft_atoi(""), atoi(""));
    printf("\nFT: %i\nsys %i\n", ft_atoi("0"), atoi("0"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("NULL"), atoi("NULL"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("1283718jkh"), atoi("1283718jkh"));
    //limit tests
    printf("\nFT: %i\nsys %i\n", ft_atoi("9223372036854775808"), atoi("9223372036854775808"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("9223372036854775807"), atoi("9223372036854775807"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("9223372036854775806"), atoi("9223372036854775806"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("9223372036854775805"), atoi("9223372036854775805"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("9223372036854775804"), atoi("9223372036854775804"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("9223372036854775803"), atoi("9223372036854775803"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("9223372036854775899"), atoi("9223372036854775899"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("-9223372036854775807"), atoi("-9223372036854775807"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("-9223372036854775808"), atoi("-9223372036854775808"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("-9223372036854775809"), atoi("-9223372036854775809"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("-9223372036854775810"), atoi("-9223372036854775810"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("-9999999999999999999"), atoi("-9999999999999999999"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("9999999999999999999"), atoi("9999999999999999999"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("2147483647"), atoi("2147483647"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("-2147483648"), atoi("-2147483648"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("2147483646"), atoi("2147483646"));
    printf("\nFT: %i\nsys %i\n", ft_atoi("2147483648"), atoi("2147483648"));

//  printf("\n\033[0;33m ft_atoi tests: \033[0m\n\n");

// 	printf("testing 2:  %d\n", ft_atoi(atoi_test));
//     printf("testing 30:  %d\n", ft_atoi(atoi_test1));
//     printf("testing -5789:  %d\n", ft_atoi(atoi_test2));
//     printf("testing 0:  %d\n", ft_atoi(atoi_test3));
//     printf("testing -2147483648:  %d\n", ft_atoi(atoi_test4));
//     printf("testing 2147483647:  %d\n", ft_atoi(atoi_test5));

//     printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
//     printf("testing 2:  %d\n", atoi(atoi_test));
//     printf("testing 30:  %d\n", atoi(atoi_test1));
//     printf("testing -5789:  %d\n", atoi(atoi_test2));
//     printf("testing 0:  %d\n", atoi(atoi_test3));
//     printf("testing -2147483648:  %d\n", atoi(atoi_test4));
//     printf("testing 2147483647:  %d\n", atoi(atoi_test5));


	return (0);
}