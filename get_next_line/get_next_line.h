#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>


size_t			ft_strlen(char *str);
char			*ft_strchr(char *str, int c);
char			*gnl_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
char			*find_line(char *save);
char			*save_line(char *save);
char			*read_file(int fd, char *save);

#endif
