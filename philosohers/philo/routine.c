/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:58:42 by smorphet          #+#    #+#             */
/*   Updated: 2023/07/03 14:40:50 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_fork(t_philo *philo)
{
	int	count;

	while (1)
	{
		count = 0;
		if (!pthread_mutex_lock(&philo->prog_info->forks[philo->fork_r]))
		{
			count++;
			if (philo->prog_info->number_of_philos == 1)
				printer(philo, "has taken a fork\n");
		}
		if (!pthread_mutex_lock(&philo->prog_info->forks[philo->fork_l]))
			count++;
		if (count == 2)
		{
			printer(philo, "has taken a fork\n");
			printer(philo, "has taken a fork\n");
			return (SUCCESS);
		}
		else
		{
			pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_r]);
			usleep(100);
		}
	}
}

static void	eat_sleep_think(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_lock(&philo->prog_info->hordor);
	philo->time_last_ate = get_time();
	pthread_mutex_unlock(&philo->prog_info->hordor);
	printer(philo, "is eating\n");
	non_usleep(philo->prog_info->time_to_eat, philo->prog_info);
	pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_r]);
	pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_l]);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->eaten_count++;
	pthread_mutex_unlock(&philo->eat_mutex);
	printer(philo, "is sleeping\n");
	non_usleep(philo->prog_info->time_to_sleep, philo->prog_info);
	printer(philo, "is thinking\n");
}

int	philo_routine(void *philo_data)
{
	t_philo	*philo;

	philo = (t_philo *)philo_data;
	pthread_mutex_lock(&philo->prog_info->hordor);
	philo->time_last_ate = get_time();
	pthread_mutex_unlock(&philo->prog_info->hordor);
	if (philo->philo_index % 2 == 0)
	{
		printer(philo, "is thinking\n");
		non_usleep(philo->prog_info->time_to_eat / 10, philo->prog_info);
	}
	while (1)
	{
		eat_sleep_think(philo);
		pthread_mutex_lock(&philo->prog_info->death_mutex);
		if (philo->prog_info->death_flag == 1)
		{
			pthread_mutex_unlock(&philo->prog_info->death_mutex);
			pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_r]);
			pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_l]);
			break ;
		}
		pthread_mutex_unlock(&philo->prog_info->death_mutex);
	}
	return (0);
}
