#include "get_next_line.h"

/*SHEREE THESE ARE FINE, THEY PASSED LIBFT DO NOT MESS WITH THEM.....THEY DO WHAT YOU WANT!*/

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strchr(const char *s, int c)
{
	char	find;

	find = c;
	while (*s)
	{
		if (*s == find)
			return ((char *)s);
		s++;
	}
	if (find == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		index;
	int		subindex;
	char	*substr;

	if (!s1)
		return (NULL);
	index = 0;
	subindex = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	substr = malloc(len + 1);
	if (substr || len == 0)
	{
		while (s1[index] != '\0')
			substr[subindex++] = s1[index++];
		index = 0;
		while (s2[index] != '\0')
		{
			substr[subindex] = s2[index++];
			subindex++;
		}
		substr[subindex] = '\0';
		return (substr);
	}
	return (NULL);
}