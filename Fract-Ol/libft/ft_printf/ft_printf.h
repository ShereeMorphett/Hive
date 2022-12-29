/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:48:42 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/22 16:01:11 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_printf(const char *input, ...);
int			ft_putstr(char *str);
int			ft_putchar(char c);
int			ft_putnbr(int n);
static int	count_hex(unsigned int num);
int			hex(unsigned int num, char *base);
static char	*hex_to_str(unsigned int num, char *base);
int			pointer(void *number, char *base);
static int	pointer_count_hex(unsigned long num);
static char	*pointer_hex_to_str(unsigned long num, char *base);

#endif 
