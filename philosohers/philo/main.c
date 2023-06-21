/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:59:20 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/21 09:06:45 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	make_threads(t_prog *prog)
{
	int	t_count;

	t_count = 0;
	pthread_mutex_lock(&prog->hordor);
	while (t_count < prog->number_of_philos)
	{
		prog->philo_array[t_count]->fork_l = t_count;
		prog->philo_array[t_count]->fork_r = (t_count + 1) % \
		prog->number_of_philos;
		prog->philo_array[t_count]->philo_index = t_count;
		prog->philo_array[t_count]->prog_info = prog;
		prog->philo_array[t_count]->eaten_count = 0;
		if (pthread_create(&prog->philo_array[t_count]->thread, NULL, \
		(void *) philo_routine, (void *) prog->philo_array[t_count]) != 0)
		{
			printf("Failed to create the thread\n");
			break ;
		}
		t_count++;
	}
	prog->start_time = get_time();
	pthread_mutex_unlock(&prog->hordor);
	monitoring(prog);
}

void	clean_up(t_prog *prog)
{
	int	count;

	count = 0;
	if (prog->philo_array)
	{
		while (count < prog->number_of_philos)
		{
			free(prog->philo_array[count]);
			count++;
		}
		free(prog->philo_array);
	}
	pthread_mutex_destroy(&prog->hordor);
	while (count < prog->number_of_philos)
	{
		pthread_mutex_destroy(&prog->forks[count]);
		count++;
	}
	if (prog->forks)
		free(prog->forks);
}

int	main(int argc, char **argv)
{
	t_prog	prog;

	if (argc != 5 && argc != 6)
	{
		printf("Incorrect number of arguments: ");
		printf("number_of_philos, time_to_die, time_to_eat, time_to_sleep. ");
		printf("Optional: number_of_times_each_philosopher_must_eat\n");
		return (0);
	}
	if (process_argv(argv, argc) == ERROR || \
	initialize_struct(argv, &prog) == ERROR)
		return (0);
	make_threads(&prog);
	ft_pthread_exit(&prog);
	pthread_join(prog.monitoring_thread, NULL);
	clean_up(&prog);
	return (0);
}
