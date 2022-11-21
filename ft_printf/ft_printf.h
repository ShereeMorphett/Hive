#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>

int    ft_printf(const char *, ...);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr(int n);
static int	count_hex(unsigned long num);
static int	hex(unsigned long num, char *base);
char	*hex_to_str(unsigned long num, char *base);
static int	pointer(void *number, char *base);

#endif 