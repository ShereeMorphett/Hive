/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:37:49 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/09 15:45:12 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void get_forks(t_philo *philo)
{
	int fork_l = philo->philo_index;
	int fork_r = (philo->philo_index + 1) % philo->prog_info->number_of_philosophers;

	pthread_mutex_lock(&philo->prog_info->forks[fork_l]);
	printer(philo, "has taken left fork\n");
	pthread_mutex_lock(&philo->prog_info->forks[fork_r]);
	printer(philo, "has taken right fork\n");
}

int eating(t_philo *philo)
{
	get_forks(philo);
	if ((get_time() - philo->time_last_ate) > philo->prog_info->time_to_die)
	{
		pthread_mutex_lock(&philo->prog_info->death_mutex);
		printer(philo, "has died\n");
		philo->prog_info->death_flag = 1;
		return (1);
	}
	philo->time_last_ate = get_time();
	printer(philo, "is eating\n");
	non_usleep(philo->prog_info->time_to_eat);
	return (1);
}

int sleeping(t_philo *philo)
{
	long int	death_time;

	death_time = get_time() - philo->time_last_ate;
	printer(philo, "is sleeping\n");
	pthread_mutex_lock(&philo->prog_info->death_mutex);
	if ((death_time + philo->prog_info->time_to_sleep) > philo->prog_info->time_to_die)
	{
		printer(philo, "has died\n");
		philo->prog_info->death_flag = 1;
		pthread_mutex_unlock(&philo->prog_info->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->prog_info->death_mutex);
	non_usleep(philo->prog_info->time_to_sleep);
	return (1);
}

void* philo_routine(void *philo_data) 
{
	t_philo *philo;

	philo = (t_philo *)philo_data;

	pthread_mutex_lock(&philo->prog_info->hordor);
	pthread_mutex_unlock(&philo->prog_info->hordor); // Synchronizes the start
	if(philo->philo_index % 2 == 0)
		sleeping(philo);
	while (1) 
	{
		if (!eating(philo))
		{ 
			philo->time_last_ate = get_time(); // Set time_last_ate when they start eating
		}
		sleeping(philo);
		printer(philo, "is thinking\n");
		if (philo->prog_info->death_flag == 1)
		{
			pthread_mutex_unlock(&philo->prog_info->death_mutex);
			break;
		}
	}
	pthread_exit(NULL);
}

void make_threads(t_prog *prog)
{
	int t_count;
	t_count = 0;
	
	pthread_mutex_lock(&prog->hordor);
	while (t_count < prog->number_of_philosophers)
	{
		int fork_l = t_count;
		int fork_r = (t_count + 1) % prog->number_of_philosophers;

		pthread_mutex_init(&prog->forks[fork_l], NULL);
		pthread_mutex_init(&prog->forks[fork_r], NULL);
		prog->philo_array[t_count]->philo_index = t_count;
		prog->philo_array[t_count]->prog_info = prog;
		if (pthread_create(&prog->philo_array[t_count]->thread, NULL, philo_routine, (void *) prog->philo_array[t_count]) != 0)
      	{
		  	printf("Failed to create the thread\n");
			break ;
		}
		t_count++;
	}
	prog->start_time = get_time();
	pthread_mutex_unlock(&prog->hordor);
}

void clean_up(t_prog *prog)
{
	int count;
	count = 0;
	if (prog->philo_array)
	{
        while(count < prog->number_of_philosophers)
		{
            free(prog->philo_array[count]);
			count++;
        }
        free(prog->philo_array);
	}
	pthread_mutex_destroy(&prog->death_mutex);
	pthread_mutex_destroy(&prog->hordor);
	count = 0;
	while (count < prog->number_of_philosophers)
	{
		pthread_mutex_destroy(&prog->forks[count]);
		count++;
	}
	if (prog->forks)
		free(prog->forks);
}

/*SHEREE, YOU CANNOT USE EXIT IN THIS PROGRAM*/
int main(int argc, char **argv)
{
    t_prog prog;
	int count;

	count = 0;
	if (argc != 5 && argc != 6) {
        printf("Incorrect number of arguments: ");
        printf("number_of_philosophers, time_to_die, time_to_eat, time_to_sleep. ");
        printf("Optional: number_of_times_each_philosopher_must_eat\n");
        return (0);
    }
	if (!process_argv(argv, argc))
        initialize_struct(argv, &prog);
	make_threads(&prog);
	count = prog.number_of_philosophers - 1;
	while (count >= 0)
	{
    	pthread_join(prog.philo_array[count]->thread, NULL);
		count--;
	}
	clean_up(&prog);
    return (0);
}