/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:04:03 by smorphet          #+#    #+#             */
/*   Updated: 2022/10/27 14:04:11 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isalnum(int argument)
{
	if (argument >= 'A' && argument <= 'Z')
		return (1);
	if (argument >= 'a' && argument <= 'z' )
		return (1);
	if (argument >= '0' && argument <= '9')
		return (1);
	else
		return (0);
}
