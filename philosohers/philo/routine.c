#include "philosophers.h"

#define SUCCESS 0

int take_fork(t_philo *philo)
{
	while (pthread_mutex_lock(&philo->prog_info->forks[philo->fork_r]))
		;
	while (pthread_mutex_lock(&philo->prog_info->forks[philo->fork_l]))
		;
	printer(philo, "has taken a fork\n");
	return (SUCCESS);
}

int eating(t_philo *philo)
{
	take_fork(philo);
	philo->time_last_ate = get_time();
	printer(philo, "is eating\n");
	non_usleep(philo->prog_info->time_to_eat);
	pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_r]);
	pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_l]);
	philo->eaten_count++; // for tracking the if finished
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

	int flag = 0;
	philo = (t_philo *)philo_data;
	philo->time_last_ate = get_time();
	pthread_mutex_lock(&philo->prog_info->hordor); 
	pthread_mutex_unlock(&philo->prog_info->hordor); //syncing
	if(philo->philo_index % 2 == 0) // potentially offset eating deadlock? , should be thinking?
		printer(philo, "is thinking\n");
	while (flag != 1) 
	{
		eating(philo);
		sleeping(philo);
		if (philo->prog_info->death_flag == 1)
		{
			pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_r]);
			pthread_mutex_unlock(&philo->prog_info->forks[philo->fork_l]);
			flag = 1;
			break;
		}
		printer(philo, "is thinking\n");
	}
	pthread_exit(NULL);
}