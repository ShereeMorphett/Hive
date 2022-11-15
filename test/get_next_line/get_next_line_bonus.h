/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:20:52 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/14 17:20:57 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
#include <unistd.h>

size_t			ft_strlen(char *str);
char			*ft_strchr(char *str, int c);
char			*gnl_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);

#endif
