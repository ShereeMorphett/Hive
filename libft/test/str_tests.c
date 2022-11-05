#include "libft.h"
#include <stdio.h>
#include <string.h>


#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KWHT  "\x1B[37m"



void    myfunc(unsigned int i, char *str_at_ft_striteri)
{     if (i == -1)
         return;

      ft_putchar_fd(*str_at_ft_striteri, 1);
      ft_putchar_fd('\n', 1);
}

int main(void)
{
    printf("\n%sTesting ft_strdup\n", KGRN);
    printf("%s\n-----Testing from libft-----\n%s", KMAG, KWHT);

    char const duplicateme[12] = "print twice";
    printf("there should be 2 of these, %s\n", duplicateme);
    char *duplicate =  ft_strdup(duplicateme);
    printf("Did it work? %s\n", duplicate);


    printf("\n%sTesting ft_strlcpy\n",KGRN);

    printf("%s\n-----Testing from libft-----\n%s", KMAG, KWHT);
    
    char strlcpy[] = "Hello there!";
    char dst[12];
    int result;
    result = strlcpy(dst, strlcpy, 10);
    printf("strlcpy: %s,  copied to %s, with length %d\n", strlcpy, dst, result);



    printf("\n%sTesting ft_strchr\n",KGRN);
    printf("%s\n-----Testing from libft-----\n%s", KMAG, KWHT);

    printf("%s\n", ft_strchr(duplicate, ' '));
    printf("%s\n", ft_strchr(duplicate, 'b'));
    printf("%s\n", ft_strchr(duplicate, 't'));
    

        printf("\n%sTesting ft_strlen\n",KGRN);

      char testlen1[5] = "this";
      char testlen2[5] = "\0";
      char testlen3[5] = "2314#";
      
    printf("%s\n-----Testing from libft-----\n%s", KMAG, KWHT);
    printf("%zu\n", ft_strlen(testlen1));

    
    
    printf("\n%sTesting ft_strrchr\n", KGRN);
    printf("%s\n-----Testing from libft-----\n%s", KMAG, KWHT);
  
    printf("%s \n", ft_strrchr(duplicate, 't'));
    printf("%s \n", ft_strrchr(duplicate, ' '));
    printf("%s\n ", ft_strrchr(duplicate, '0'));


    printf("\n%sTesting ft_strncmp\n", KGRN);
    printf("%s\n-----Testing from libft-----\n%s", KMAG, KWHT);
    
    const char strcmp1[7] = "  www";
    const char strcmp2[7] = "kk";
    int ret = ft_strncmp(strcmp1, strcmp2, 4);
   if(ret < 0) {
      printf("strcmp1 is less than str2");
   } else if(ret > 0) {
      printf("strcmp2 is less than str1");
   } else {
      printf("strcmp1 is equal to strcmp2");
   }






   printf("\n%sTesting ft_strtrim\n", KGRN);

   printf("%s\n-----Testing from libft-----\n%s", KMAG, KWHT);

    printf("\n%sTesting ft_strtrim%s\n", KMAG, KWHT);
    char const *string_trim = "abc stuff abc";
    char const *set = "abc ";
    char *new_string = ft_strtrim(string_trim, set);

   printf("%s \n", string_trim);
   printf("%s \n", new_string);


   printf("\n%sTesting ft_split\n", KGRN);

   printf("%s\n-----Testing from libft-----\n%s", KMAG, KWHT);
   printf("\n%sTesting ft_split%s\n", KMAG, KWHT);

    char const *string_split = "does this work";
    printf("is the seg in printing");
    char **new_split = ft_split(string_split, ' ');
   printf("%c \n", *new_split[0]);

   printf("\n%sTesting ft_strnstr\n", KGRN);

   printf("%s\n-----Testing from libft-----\n%s", KMAG, KWHT);
      const char *haystack = "does this work";
      const char *needle = "this";
      char *ptr = ft_strnstr(haystack, needle, 12);

    printf("Libft output = %s", ptr);

    printf("%s \n-----Testing from original-----\n%s", KBLU, KWHT);
   char *og_ptr = strnstr(haystack, needle, 12);
    printf("Libft output = %s", ptr);
   return (0);
}
