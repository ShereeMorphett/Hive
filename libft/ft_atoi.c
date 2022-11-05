/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:51:11 by smorphet          #+#    #+#             */
/*   Updated: 2022/10/24 16:53:00 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int			index;
	int			sign;
	long long	result;

	index = 0;
	sign = 1;
	result = 0;
	while (str[index] == ' ' || ((9 <= str[index]) && (str[index] <= 13)))
		index++;
	if (str[index] == '+')
		index++;
	else if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	while (str[index] && ('0' <= str[index]) && (str[index] <= '9'))
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	if (result * sign > 2147483648)
		return (-1);
	if (result * sign < -2147483648)
			return (0);
	return (sign * result);
}


