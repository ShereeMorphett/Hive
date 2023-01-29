#include <stdio.h>    
#include <stdlib.h>
#include <time.h>
#define KMAG  "\x1B[35m"
#define KWHT  "\x1B[37m"
int main()  
{  
    int num;  
    printf ("getting exam.... \n");  
    srand(time(0));
    num = rand() % 12;
    printf ("%d\n", num);   
    printf("%s ----LEVEL 1---- %s\n", KMAG, KWHT);
    if (num == 0)
        printf("first_word\n");
    else if (num == 1)
        printf("fizzbuzz\n");
    else if (num == 2)
        printf("ft_strcpy\n");
    else if (num == 3)
        printf("ft_strlen\n");
    else if (num == 4)
        printf("ft_swap\n");
    else if (num == 5)
        printf("putstr\n");
    else if (num == 6)
        printf("repeat_alpha\n");
    else if (num == 7)
        printf("rev_print\n");
    else if (num == 8)
        printf("rot_13\n");
    else if (num == 9)
        printf("rotone\n");
    else if (num == 10)
        printf("search_and_replace\n");
    else if (num == 11)
        printf("ulstr \n");

    num = rand() % 20;
    printf("\n%s ----LEVEL 2---- %s\n", KMAG, KWHT);
    if (num == 0)
        printf("alpha_mirror\n");
    else if (num == 1)
        printf("camel_to_snake\n");
    else if (num == 2)
        printf("do_op\n");
    else if (num == 3)
        printf("ft_atoi\n");
    else if (num == 4)
        printf("ft_strcmp\n");
    else if (num == 5)
        printf("ft_strcspn\n");
    else if (num == 6)
        printf("ft_strdup\n");
    else if (num == 7)
        printf("ft_strpbrk\n");
    else if (num == 8)
        printf("ft_strrev\n");
    else if (num == 9)
        printf("ft_strspn\n");
    else if (num == 10)
        printf("inter\n");
    else if (num == 11)
        printf("is_power_of_2 \n");
        else if (num == 12)
        printf("last_word\n");
    else if (num == 13)
        printf("max\n");
    else if (num == 14)
        printf("print_bits\n");
    else if (num == 15)
        printf("reverse_bits\n");
    else if (num == 16)
        printf("snake_to_camel\n");
    else if (num == 17)
        printf("swap_bits\n");
    else if (num == 18)
        printf("union \n");
    else if (num == 19)
        printf("wdmatch \n");

    num = rand() % 15;
    printf("\n%s ----LEVEL 3---- %s\n", KMAG, KWHT);
    if (num == 0)
        printf("add_prime_sum\n");
    else if (num == 1)
        printf("epur_str\n");
    else if (num == 2)
        printf("expand_str\n");
    else if (num == 3)
        printf("ft_atoi_base\n");
    else if (num == 4)
        printf("ft_list_size\n");
    else if (num == 5)
        printf("ft_range\n");
    else if (num == 6)
        printf("ft_rrange\n");
    else if (num == 7)
        printf("hidenp\n");
    else if (num == 8)
        printf("lcm\n");
    else if (num == 9)
        printf("paramsum\n");
    else if (num == 10)
        printf("pgcd\n");
    else if (num == 11)
        printf("print_hex \n");
        else if (num == 12)
        printf("rstr_capitalizer\n");
    else if (num == 13)
        printf("str_capitalizer\n");
    else if (num == 14)
        printf("tab_mult\n");
    

    num = rand() % 10;
    printf("\n%s ----LEVEL 4---- %s\n", KMAG, KWHT);
    if (num == 0)
        printf("flood_fill\n");
    else if (num == 1)
        printf("fprime\n");
    else if (num == 2)
        printf("ft_itoa\n");
    else if (num == 3)
        printf("ft_list_foreach\n");
    else if (num == 4)
        printf("ft_list_remove_if\n");
    else if (num == 5)
        printf("ft_split\n");
    else if (num == 6)
        printf("rev_wstr\n");
    else if (num == 7)
        printf("rostring\n");
    else if (num == 8)
        printf("sort_int_tab\n");
    else if (num == 9)
        printf("sort_list\n");

    return (0);  
    }  