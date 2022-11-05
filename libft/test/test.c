#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <strings.h>

#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KWHT  "\x1B[37m"
#define EMPTY_STRING  ""


void    myfunc(unsigned int i, char *str_at_ft_striteri)
{
        ft_putchar_fd(*str_at_ft_striteri, 1);
        printf("\n");
}

void ft_strlcpy_test(int size)
{
    char string[] = "Hello there";
    char buffer[11];
    int r;

    r = strlcpy(buffer,string,size);

    printf("Copied '%s' into '%s', length %d\n",
            string,
            buffer,
            r
          );
}

void strlcpy_test(int size)
{
    char string[] = "Hello there";
    char buffer[11];
    int r;

    r = strlcpy(buffer,string,size);

    printf("Copied '%s' into '%s', length %d\n",
            string,
            buffer,
            r
          );
}

int main(void)
{
    printf("%sTesting ft_isalpha\n %s", KGRN, KWHT);

    printf("%s \n-----Testing from libft-----\n %s", KMAG, KWHT);
    
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

    printf("%s\n-----Testing from original-----\n %s", KBLU, KWHT);

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
    printf("%s \n-----Testing from libft-----\n %s", KMAG, KWHT);
    
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

    printf("%s \n-----Testing from original-----\n %s", KBLU, KWHT);

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

    printf("%s \n-----Testing from libft-----\n %s", KMAG, KWHT);

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

    printf("%s \n-----Testing from original-----\n %s", KBLU, KWHT);

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
    printf("%s \n-----Testing from libft-----\n %s", KMAG, KWHT);

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

    
    printf("%s \n-----Testing from original-----\n %s", KBLU, KWHT);

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

    printf("%s \n-----Testing from original-----\n %s", KBLU, KWHT);

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



    printf("\n%sTesting ft_strlen\n", KGRN);
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);
    
    printf("this should have 4:     %zu\n", (ft_strlen("1234")));
    printf("this should have 10:     %zu\n", (ft_strlen(" g g h r e")));
    printf("this should have 4 (space):     %zu\n", (ft_strlen("    ")));

    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    printf("this should have 4:     %lu\n", strlen("1234"));
    printf("this should have 10:     %lu\n", strlen(" g g h r e"));
    printf("this should have 4 (space):     %lu\n", strlen("    "));
    

    printf("\n%sTesting ft_memset \n", KGRN);
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);
    int n = 10;
    char ftmemset_arr[50] = "does this thing actually function";

    ft_memset(ftmemset_arr, '0', n*sizeof(ftmemset_arr[0]));
    printf("\nArray after ft_memset()\n");
    printf("%s \n", ftmemset_arr);

    ft_memset(ftmemset_arr, '-', (0));
    printf("\nArray after ft_memset()\n");
    printf("%s \n", ftmemset_arr);

    ft_memset(ftmemset_arr, 'A', n*sizeof(ftmemset_arr[0]));
    printf("\nArray after ft_memset()\n");
    printf("%s \n", ftmemset_arr);
    
    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    n = 10;
    char memset_arr[50] = "does this thing actually function";
    memset(memset_arr, '0', n*sizeof(memset_arr[0]));
    printf("\nArray after memset()\n");
    printf("%s \n", memset_arr);

    memset(memset_arr, '-', (0));
    printf("\nArray after memset()\n");
    printf("%s \n", memset_arr);

    memset(memset_arr, 'A', n*sizeof(memset_arr[0]));
    printf("\nArray after memset()\n");
    printf("%s \n", memset_arr);


  printf("\n%sTesting ft_bzero\n", KGRN);
    
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);
    char str[18] = "does this work";
    size_t len = 2;
    
    printf("\nBefore ft_bzero(): %s\n", str);
    ft_bzero(str, len);
    printf("index 0 after ft_bzero():  %d\n", str[0]);
    printf("index 1 after ft_bzero():  %d\n", str[1]);
    printf("index 2 after ft_bzero():  %c\n", str[2]);
    printf("index 3 after ft_bzero():  %c\n", str[3]);
    
    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    char og_bzero[18] = "does this work";    
    printf("\nBefore original bzero(): %s\n", og_bzero);
    bzero(og_bzero, len);
    printf("index 0 after ft_bzero():  %d\n", og_bzero[0]);
    printf("index 1 after ft_bzero():  %d\n", og_bzero[1]);
    printf("index 2 after ft_bzero():  %c\n", og_bzero[2]);
    printf("index 3 after ft_bzero():  %c\n", og_bzero[3]);

    
    printf("\n%sTesting ft_memcpy\n", KGRN);
    
    char memcpy_str1[] = "stuff"; 
    char memcpy_str2[] = "works"; 
    char og_memcpy_str1[] = "stuff"; 
    char og_memcpy_str2[] = "works"; 
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);

    printf("str1 before ft_memcpy: %s   %s\n", memcpy_str1, memcpy_str2); 
    ft_memcpy(memcpy_str1, memcpy_str2, sizeof(memcpy_str2));
    printf("\nstr1 after ft_memcpy: %s   %s\n", memcpy_str1, memcpy_str2);

    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    printf("str1 before original memcpy: %s   %s\n", og_memcpy_str1, og_memcpy_str2); 
    memcpy(memcpy_str1, memcpy_str2, sizeof(memcpy_str2));
    printf("\nstr1 after original memcpy: %s   %s\n", og_memcpy_str1, og_memcpy_str2);


    printf("\n%sTesting ft_memmove\n", KGRN);
    
    char memmove_dest[] = "abcdef";
    const char memmove_src[]  = "123456";
	char ftmemmove_dest[] = "abcdef";
    const char ftmemmove_src[]  = "123456";
    
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);
    printf("Before ft_memmove:		dest = %s, src = %s\n\n", ftmemmove_dest, ftmemmove_src);
    ft_memmove(ftmemmove_dest, ftmemmove_src, 5);
    printf("After ft_memmove:		 dest = %s, src = %s\n\n", ftmemmove_dest, ftmemmove_src);

    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    printf("Before memmove:		dest = %s, src = %s\n\n", memmove_dest, memmove_src);
    memmove(memmove_dest, memmove_src, 5);
    printf("After memmove:		 dest = %s, src = %s\n\n", memmove_dest, memmove_src);
    
	char memmove_str[100] = "testing12345";
    char ftmemmove_str[100] = "testing12345";
    char *first = ftmemmove_str;
    char *second = ftmemmove_str;
    char *third = memmove_str;
    char *fourth = memmove_str;
	ft_memmove(second + 8, first, 10);
    printf("ft_memmove overlap : %s\n ", ftmemmove_str);
	memmove(third + 8, fourth, 10);
    printf("memmove overlap : %s\n ", memmove_str);


    printf("\n%sTesting ft_strlcpy\n", KGRN);
 

    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);  
    ft_strlcpy_test(8);
    printf("\n");
    ft_strlcpy_test(10);
        printf("\n");
    ft_strlcpy_test(0);
        printf("\n");


    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    strlcpy_test(8);
    printf("\n");
    strlcpy_test(10);
    printf("\n");
    strlcpy_test(0);
    printf("\n");

    printf("\n%sTesting ft_strlcat\n", KGRN);
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);
    
    char part_1[] = "This should ";
    char part_2[] = "make a very long string";
    int ft_strlcat_result;
    
    int size = 10;
    char buffer[size];
    strcpy(buffer,part_1);
    ft_strlcat_result = ft_strlcat(buffer, part_2, size);
    printf("%s \n", buffer);
    printf("Value returned: %d\n",ft_strlcat_result);
    if( ft_strlcat_result > size )
        printf("String truncated");
    else
        printf("String was fully copied");

    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    int strlcat_result;
    char og_part_2[] = "123456";
    strcpy(buffer,part_1);
    strlcat_result = strlcat(buffer, og_part_2, size);
     printf("%s \n", buffer);
    printf("Value returned: %d\n",strlcat_result);
    printf("%s \n", og_part_2);

    if( (int) strlcat_result > size )
        printf("String truncated\n");
    else
        printf("String was fully copied\n");
 
    printf("\n%sTesting ft_toupper\n %s", KGRN, KWHT);  
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);  
    printf("this should be g in upper: %c \n", ft_toupper('g'));
    printf("this should be b in upper: %c \n", ft_toupper('b'));
    printf("this should be a in upper: %c \n", ft_toupper('A'));
    printf("this should be $ %c: ", ft_toupper('$'));


    printf("%s\nTesting ft_tolower\n %s", KGRN, KWHT);  
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);      
    printf("this should be g in lower: %c \n", ft_tolower('g'));
    printf("this should be b in lower: %c \n", ft_tolower('b'));
    printf("this should be a in lower: %c\n", ft_tolower('A'));
    printf("this should be $:%c \n", ft_tolower('$'));


    printf("%sTesting ft_isalpha\n %s", KGRN, KWHT);

    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);  
    char const duplicateme[12] = "print twice";
    printf("there should be 2 of these, %s\n", duplicateme );
    char *duplicate =  ft_strdup(duplicateme);
    printf("Did it work? %s\n", duplicate);
    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    char *og_duplicate =  strdup(duplicateme);
    printf("Did it work? %s\n", og_duplicate);


    printf("\n%sTesting ft_strchr\n", KGRN);  
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT); 
    printf("%s\n", ft_strchr(duplicateme, ' '));
    printf("%s\n", ft_strchr(duplicateme, 'p'));
    printf("%s\n", ft_strchr(duplicateme, '\0'));
    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    printf("%s\n", strchr(duplicateme, ' '));
    printf("%s\n", strchr(duplicateme, 'p'));
    printf("%s\n", strchr(duplicateme, '\0'));
    
    
    printf("\n%sTesting ft_strrchr\n", KGRN);  
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT); 
    printf("%s \n", ft_strrchr(duplicateme, 't'));
    printf("%s \n", ft_strrchr(duplicateme, ' '));
    printf("%s\n ", ft_strrchr(duplicateme, '0'));
    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    printf("%s \n", ft_strrchr(duplicateme, 't'));
    printf("%s \n", ft_strrchr(duplicateme, ' '));
    printf("%s\n ", ft_strrchr(duplicateme, '0'));


    printf("\n%sTesting ft_strncmp\n", KGRN);
    printf("%s\n-----Testing from libft-----\n\n%s", KMAG, KWHT);
    
    const char strcmp1[7] = "1234567";
    const char strcmp2[7] = "12345";
    int ret = ft_strncmp(strcmp1, strcmp2, 4);
   if(ret < 0) {
      printf("strcmp1 is less than str2");
   } else if(ret > 0) {
      printf("strcmp2 is less than str1");
   } else {
      printf("strcmp1 is equal to strcmp2");
   }
    
    printf("%s \n\n-----Testing from original-----\n\n%s", KBLU, KWHT);
    
    ret =   strncmp(strcmp1, strcmp2, 4);
    if(ret < 0) {
      printf("strcmp1 is less than str2\n");
   } else if(ret > 0) {
      printf("strcmp2 is less than str1\n");
      printf("strcmp2 is less than str1\n");
   } else {
      printf("strcmp1 is equal to strcmp2 \n");
   }


	char *big = "abcdef";
	char *little = "abcdefghijklmnop";
	size_t strncmp_size = 6;
	int i1 = ((strncmp(big, little, strncmp_size) > 0) ? 1 : ((strncmp(big, little, strncmp_size) < 0) ? -1 : 0));
	int i2 = ((ft_strncmp(big, little, strncmp_size) > 0) ? 1 : ((ft_strncmp(big, little, strncmp_size) < 0) ? -1 : 0));
    printf("\nft_strncmp: %d \n", i2);
    
    printf("original: %d \n", i1);
    
    if (i1 == i2)
		printf("this is the correct output\n");
    else
        printf("this is the correct output\n");
	

    printf("\n%sTesting ft_memchr this needs more work\n", KGRN);
    // duplicateme[12] = "print twice"
    printf("\n%sTesting ft_strchr\n", KGRN);  
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT); 
    printf("%s\n", ft_memchr(duplicateme, ' ', 7));
    printf("%s\n", ft_memchr(duplicateme, 'p', 13));
    printf("output from search for null:|%s|\n", ft_memchr(duplicateme, '\0', 12));
    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    printf("%s\n", memchr(duplicateme, ' ', 7));
    printf("%s\n", memchr(duplicateme, 'p', 13));
    printf("output from search for null:|%s|\n", memchr(duplicateme, '\0', 12));

    //--------------------------------------------------------------------------------------
    printf("\n%sTesting ft_memcmp\n", KGRN);
   char str1[15] = "1234";
   char str2[15] = "1234";
   char str3[15] = "123456789abc";
   printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);
   ret = ft_memcmp(str1, str2, 5);
    if(ret > 0) 
        printf("str2 is less than str1");
    else if(ret < 0)
        printf("str1 is less than str2");
    else 
        printf("str1 is equal to str2");
    
    ret = ft_memcmp(str1, str3, 6);
    if(ret > 0) 
        printf("str2 is less than str1");
    else if(ret < 0)
        printf("str1 is less than str2");
    else 
        printf("str1 is equal to str2");


    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    ret = memcmp(str1, str2, 5);
    if(ret > 0) 
        printf("str2 is less than str1");
    else if(ret < 0)
        printf("str1 is less than str2");
    else 
        printf("str1 is equal to str2");
    
    ret = memcmp(str1, str3, 6);
    if(ret > 0) 
        printf("str2 is less than str1");
    else if(ret < 0)
        printf("str1 is less than str2");
    else 
        printf("str1 is equal to str2");

//-------------------------------------------------------------------------------------------
    printf("\n%sTesting ft_strnstr\n", KGRN);
    printf("%s\n-----Testing from libft-----\n%s", KMAG, KWHT);
      const char *haystack = "does this work";
      const char *needle = "this";
      char *strnstr_ptr = ft_strnstr(haystack, needle, 12);
      printf("Libft output = %s", strnstr_ptr);
      
      printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
      char *strnog_ptr = strnstr(haystack, needle, 12);
      printf("Libft output = %s", strnog_ptr);

    

        printf("%s \n\n\n==========%s PART 2%s ==========%s \n", KBLU, KMAG, KBLU, KWHT);
    
    printf("\n%s Testing ft_strjoin %s\n", KMAG, KWHT);
    printf("this should print - does this work \n");
    char const s1[11] = "does this ";
    char const s2[10] = "work\n";
    
    char const *newstring = ft_strjoin(s1, s2);
    printf("%s\n", newstring);
    


    printf("\n%s Testing ft_itoa %s\n", KMAG, KWHT);

    printf("This should be 12345:   %s/n", ft_itoa(12345));
    printf("This should be 10:   %s/n", ft_itoa(10));
    printf("This should be 0:  %s/n", ft_itoa(0));
    printf("This should be -2147483648:   %s/n", ft_itoa(-2147483648));
    printf("This should be 2147483648:   %s/n", ft_itoa(2147483648));

    printf("\n%sTesting ft_striteri%s\n\n", KMAG, KWHT);
     char  *stuff;
     stuff = "work\n";
     ft_striteri(stuff, myfunc);

     printf("%s\n", stuff);

    printf("%sTesting ft_substr%s\n", KMAG, KWHT);
    char const string[18] = "make a sub string";

    printf("%s \n", string);
    char *substring = ft_substr(string, 0, 18);
    printf("return for whole string: %s\n", substring);
    
    substring = ft_substr(string, 2, 10);
    printf("return for start = 2 and len = 10 string: %s\n", substring);
    printf("%s", string);

    substring = ft_substr(string, 18, 18);
    printf("return when len and start are =: %s\n", substring);
    
    printf("%s", string);
    substring = ft_substr(string, 20, 18);
    printf("return when start > len are =: %s\n", substring);
    
    printf("%s", string);
    
    substring = ft_substr(EMPTY_STRING, 20, 18);
    printf("return when *s is empty are =: %s\n", substring);

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
