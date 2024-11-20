/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:51:11 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/07 17:20:01 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
static int	check_result(long long result, int sign)
{
	if (sign > 0)
		return (-1);
	else if (sign < 0)
		return (0);
	else
		return (result);
}

int	ft_atoi(const char *str)
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
	if (result < 0)
		result = check_result(result, sign);
	return (result * sign);
}
