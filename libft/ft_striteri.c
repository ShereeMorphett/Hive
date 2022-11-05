/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:07:15 by smorphet          #+#    #+#             */
/*   Updated: 2022/10/27 14:07:18 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_striteri(char *s, void (*f)(unsigned int,
char*))
{
    unsigned int index;
    index = 0;

    if (!s)
        return;
        
    while (s[index])
    {
      f(index, &s[index]);
      index++;
    }

}