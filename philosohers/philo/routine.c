/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:58:42 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/15 14:59:46 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int take_fork(t_philo *philo)
{
	while (pthread_mutex_lock(&philo->prog_info->forks[philo->fork_r]))
		;
	printer(philo, "has taken a fork\n");
	while (pthread_mutex_lock(&philo->prog_info->forks[philo->fork_l]))
		;
	printer(philo, "has taken a fork\n");
	return (SUCCESS);
}

static void eating(t_philo *philo)
{
	take_fork(philo);
	philo->time_last_ate = get_time();
	printer(philo, "is eating\n");
	non_usleep(philo->prog_info->time_to_eat);
	pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_r]);
	pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_l]);
	philo->eaten_count++;
}

static void sleeping(t_philo *philo)
{
	printer(philo, "is sleeping\n");
	non_usleep(philo->prog_info->time_to_sleep);
}


/*	POTENTIALLY BETTER BUT LAPTOP IS SHIT AND I CANT CHECK IF IT RUNS BETTER ATM

void* philo_routine(void *philo_data)
{
	t_philo *philo;
	int flag = 0;
	philo = (t_philo *)philo_data;
	philo->time_last_ate = get_time();
	pthread_mutex_lock(&philo->prog_info->hordor);
	pthread_mutex_unlock(&philo->prog_info->hordor);
	if (philo->philo_index % 2 == 0)
		printer(philo, "is thinking\n");
	while (flag != 1) 
	{
		eating(philo);
		sleeping(philo);
		if (philo->prog_info->death_flag == 1)
		{
			pthread_mutex_lock(&philo->prog_info->death_mutex);
			pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_r]);
			pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_l]);
			pthread_mutex_unlock(&philo->prog_info->death_mutex);
			flag = 1;
			break;
		}
		printer(philo, "is thinking\n");
	}
	pthread_exit(NULL);
}
*/

void* philo_routine(void *philo_data)
{
	t_philo *philo;

	int flag = 0;
	philo = (t_philo *)philo_data;
	philo->time_last_ate = get_time();
	pthread_mutex_lock(&philo->prog_info->hordor); 
	pthread_mutex_unlock(&philo->prog_info->hordor);
	if(philo->philo_index % 2 == 0)
		printer(philo, "is thinking\n");
	while (flag != 1) 
	{
		eating(philo);
		sleeping(philo);
		pthread_mutex_lock(&philo->prog_info->death_mutex); 
		if (philo->prog_info->death_flag == 1)
		{
			pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_r]);
			pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_l]);
			flag = 1;
			break;
		}
		pthread_mutex_unlock(&philo->prog_info->death_mutex);
		printer(philo, "is thinking\n");
	}
	pthread_mutex_unlock(&philo->prog_info->death_mutex);
	pthread_exit(NULL);
}
