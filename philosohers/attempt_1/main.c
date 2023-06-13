/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:37:49 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/12 15:30:35 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void make_threads(t_prog *prog)
{
	int t_count;
	t_count = 0;
	
	pthread_mutex_lock(&prog->hordor);
	while (t_count < prog->number_of_philos)
	{
		prog->philo_array[t_count]->fork_l = t_count;
		prog->philo_array[t_count]->fork_r = (t_count + 1) % prog->number_of_philos;
		pthread_mutex_init(&prog->forks[prog->philo_array[t_count]->fork_l], NULL);
		pthread_mutex_init(&prog->forks[prog->philo_array[t_count]->fork_r], NULL);
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
	pthread_create(&prog->monitoring_thread, NULL, monitoring, (void *) prog);
}

void clean_up(t_prog *prog)
{
	int count;
	count = 0;
	if (prog->philo_array)
	{
        while(count < prog->number_of_philos)
		{
            free(prog->philo_array[count]);
			count++;
        }
        free(prog->philo_array);
	}
	pthread_mutex_destroy(&prog->death_mutex);
	pthread_mutex_destroy(&prog->hordor);
	count = 0;
	while (count < prog->number_of_philos)
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
        printf("number_of_philos, time_to_die, time_to_eat, time_to_sleep. ");
        printf("Optional: number_of_times_each_philosopher_must_eat\n");
        return (0);
    }
	if (!process_argv(argv, argc))
        initialize_struct(argv, &prog);
	make_threads(&prog);
	count = prog.number_of_philos - 1;
	while (count >= 0)
	{
    	pthread_join(prog.philo_array[count]->thread, NULL);
		count--;
	}
	pthread_join(prog.monitoring_thread, NULL);
	clean_up(&prog);
    return (0);
}