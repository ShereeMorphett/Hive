/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:22:21 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/12 15:43:24 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog_info->forks[philo->fork_r]);
	printf("%d is holding right fork %d\n", philo->philo_index, philo->fork_r);
	printer(philo, "has taken right fork\n");
	//printer(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->prog_info->forks[philo->fork_l]);
	printf("%d is holding left fork %d\n", philo->philo_index, philo->fork_l);
	//printer(philo, "has taken a fork\n");
	printer(philo, "has taken left fork\n");
	philo->time_last_ate = get_time();
	printer(philo, "is eating\n");
	non_usleep(philo->prog_info->time_to_eat);
	pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_r]);
	pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_l]);
	return (1);
}

int sleeping(t_philo *philo)
{
	printer(philo, "is sleeping\n");
	non_usleep(philo->prog_info->time_to_sleep);
	return (1);
}

void* philo_routine(void *philo_data)
{
	t_philo *philo;

	philo = (t_philo *)philo_data;
	pthread_mutex_lock(&philo->prog_info->hordor);
	philo->time_last_ate = get_time();
	pthread_mutex_unlock(&philo->prog_info->hordor);
	
	if(philo->philo_index % 2 == 0) // potentially offset eating deadlock? , should be thinking?
	{
		printer(philo, "is thinking\n");
		usleep(3000);
	}
	while (1) 
	{
		eating(philo);
		sleeping(philo);
		pthread_mutex_lock(&philo->prog_info->death_mutex);
		if (philo->prog_info->death_flag == 1)
		{
			printf("has registered a death and unlocked the death mutex\n");
			break;
		}
		pthread_mutex_unlock(&philo->prog_info->death_mutex);
		printer(philo, "is thinking\n");
	}
	pthread_exit(NULL);
}
