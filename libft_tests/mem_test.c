#include "libft.h"
#include <stdio.h>
#include <string.h>

#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KWHT  "\x1B[37m"

int main(void)
{    
    printf("\n%sTesting ft_bzero THIS TEST NEEDS MORE WORK\n", KGRN);
    
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);
    char str[18] = "does this work";
    size_t len = 2;
    
    printf("\nBefore ft_bzero(): %s\n", str);
    ft_bzero(str, len);
    printf("After ft_bzero():  %s\n", &str[4]);

    
    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    char og_bzero[18] = "does this work";    
    printf("\nBefore original bzero(): %s\n", og_bzero);
    bzero(og_bzero, len);
    printf("After orignal bzero():  %s\n", og_bzero);



    printf("\n%sTesting ft_memset THIS TEST NEEDS MORE WORK\n", KGRN);
    
    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);
    char memset_str[18] = "does this work";
   
    
    printf("\nBefore ft_memset(): %s\n", memset_str);
    ft_memset(memset_str, 'a' , len);
    
    printf("After ft_memset():  %s\n", memset_str);

    
    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);

    char og_memset[18] = "does this work";    
    printf("\nBefore original memset(): %s\n", og_memset);
    memset(og_memset, 'a' ,len);
    printf("After orignal memset:  %s\n", og_memset);
 


    
    printf("\n%sTesting ft_memcpy\n", KGRN);
    
    const void *cpy_src = "does this work";

    void * ft_cpy[15];
    void * og_cpy[15];

    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);
    
    printf("After ft_memcpy():  %s\n", ft_memcpy(ft_cpy, cpy_src, 7));

    
    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    
    printf("After orignal memcpy:  %s\n", memcpy(og_cpy, cpy_src, 7));


    printf("\n%sTesting ft_memcmp\n", KGRN);
   char str1[15];
   char str2[15];
   int ret;

   memcpy(str1, "abcdef", 6);
   memcpy(str2, "ABCDEF", 6);

   ret = memcmp(str1, str2, 5);

    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);

   if(ret > 0) {
      printf("str2 is less than str1");
   } else if(ret < 0) {
      printf("str1 is less than str2");
   } else {
      printf("str1 is equal to str2");
   }
    
  printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);
    ret = ft_memcmp(str1, str2, 5);

    printf("\n%sTesting ft_memmove THIS TEST NEEDS MORE WORK\n", KGRN);
    
    const void *memmove_src = "does this work";

    void * memove_dest[15];
    void * og_dest[15];

    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    
       memmove(og_dest, memmove_src, 4);

       printf("\nAfter memmove(): %s\n", memmove(og_dest, memmove_src, 4));


    printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);

    printf("\nAfter ft_memmove(): %s\n", ft_memmove(memove_dest, memmove_src, 4));


    printf("\n%sTesting ft_memchr\n", KGRN);
    
    char s[] = "stuff c and";
    char *ptr = memchr(s,'c',sizeof(s));

    
     printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
    printf("output from original memchr \n\n\n");
    if (ptr != NULL)
    {
        printf ("'c' found at position %ld.\n", ptr-s+1);
        printf ("search character found:  %s\n", ptr);
    }
    else
    {
        printf ("search character not found\n");
    }


   printf("%s \n-----Testing from libft-----\n%s", KMAG, KWHT);
   

    *ptr = ft_memchr(s,'c',sizeof(s));

    if (ptr != NULL)
    {
        printf ("'c' found at position %ld.\n", ptr-s+1);
        printf ("search character found:  %s\n", ptr);
    }
    else
    {
        printf ("search character not found\n");
    }

    return (0);
}
