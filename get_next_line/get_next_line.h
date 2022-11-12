
#ifndef LIBFT_H
# define LIBFT_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 4096

char *get_next_line(int fd);
char	*get_line(char *holder);
char	*update_hold(char *holder);
char	*read_string_to_hold(int fd, char *holder);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif