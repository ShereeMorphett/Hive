/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:37:49 by smorphet          #+#    #+#             */
/*   Updated: 2023/05/25 13:37:51 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*input:	number_of_philosophers time_to_die time_to_eat
			time_to_sleep [number_of_times_each_philosopher_must_eat]
External functs: memset, printf, malloc, free, write, sleep, gettimeofday, pthread_create,
				 pthread_detach, pthread_join, pthread_mutex_init,
				 pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
input:				 
◦ number_of_philosophers: The number of philosophers and also the number of forks.

◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning
	of their last meal or the beginning of the sim- ulation, they die.

◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.

◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

◦ number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten
	at least number_of_times_each_philosopher_must_eat times, the simulation stops.
	If not specified, the simulation stops when a philosopher dies.
				 */

static int	check_result(result, sign)
{
	if (sign > 0)
		return (-1);
	else if (sign < 0)
		return (0);
	else
		return (result);
}

static int	ph_atoi(const char *str)
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


static void initialize_struct(char **argv, t_philo *philo)
{
	if (argv[1])
	{
		philo->number_of_philosophers = ph_atoi(argv[1]);
		if (philo->number_of_philosophers == 0)
		{
			printf("Number of philosophers must be more than 0\n");
			exit (0);
		}
	}
	if (argv[2])
		philo->time_to_die = ph_atoi(argv[2]);
	if (argv[3])
		philo->time_to_eat = ph_atoi(argv[3]);
	if (argv[4])
		philo->time_to_sleep = ph_atoi(argv[4]);
	if (argv[5])
		philo->number_times_eat = ph_atoi(argv[4]);
}


int main (int argc, char **argv)
{
	t_philo philo;

	if (argc != 5 && argc != 6)
	{
		printf("Incorrect number of arguments: ");
		printf("number_of_philosophers, time_to_die, time_to_eat, time_to_sleep. ");
		printf("Optional: number_of_times_each_philosopher_must_eat");
		return (0);
	}
	initialize_struct(argv, &philo);
	// if (validate_input(&philo))
	// 	return (0);
	
	return (0);
}
