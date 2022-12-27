/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:06:08 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/03 16:43:03 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isprint(int argument)
{
	if (argument < 32 || argument > 126)
		return (0);
	return (1);
}
