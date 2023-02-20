/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:41:30 by smorphet          #+#    #+#             */
/*   Updated: 2023/02/20 10:45:21 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str); */

int ft_strlen(char *str)
{
	int index = 0;
	
	while(str[index])
	{
		index++;
	
	}

	return(index);
}

