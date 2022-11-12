#include "get_next_line.h"

/*SHEREE THESE ARE FINE, THEY PASSED LIBFT DO NOT MESS WITH THEM.....THEY DO WHAT YOU WANT!*/

size_t	ft_strlen(char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strchr(char *str, int c)
{
	int		index;
	char	find;

	find = c;
	index = ft_strlen(str);
	if (str == '\0')
		return (NULL);
	while (index >= 0)
	{
		if (str[index] == find)
			return ((char *) &str[index]);
		index--;
	}
	if (index == 0)
		return (NULL);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
