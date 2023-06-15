/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:59:06 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/14 16:59:08 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_result(long long result, int sign)
{
	if (sign > 0)
		return (-1);
	else if (sign < 0)
		return (0);
	else
		return (result);
}

int	ph_atoi(const char *str)
{
	int index = 0;
	int sign = 1;
	long long result = 0;

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

static int	check_number(char *string)
{
	int num = ph_atoi(string);
	int index = 0;

	while (string[index] != '\0')
	{
		if (string[index] == '-' || string[index] == '+')
			index++;
		if (string[index] < '0' || string[index] > '9')
			return (0);
		index++;
	}
	if (string[0] != '-' && num < 0)
		return (0);
	if (string[0] == '-' && num >= 0)
		return (0);
	return (1);
}
int	process_argv(char *argv[], int argc)
{
	int index = 1;

	while (index < argc)
	{
		if (!check_number(argv[index]))
		{
			printf("Input must only contain positive numerical values\n");
			return (1);
		}
		index++;
	}
	return (0);
}
