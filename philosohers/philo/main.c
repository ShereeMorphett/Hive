/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:37:49 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/08 13:16:55 by smorphet         ###   ########.fr       */
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

static void initialize_struct(char **argv, t_prog *prog) 
{
	int count;
	count = 0;
    if (argv[1] && (prog->number_of_philosophers = ph_atoi(argv[1])) == 0) {
        printf("Number of philosophers must be more than 0\n");
        exit(0);
    }
	prog->philo_array = malloc(sizeof (t_philo) * prog->number_of_philosophers);
	if(!prog->philo_array)
		exit(EXIT_FAILURE);
	prog->death_flag = 0;
	while (count < prog->number_of_philosophers)
	{
		prog->philo_array[count] = malloc(sizeof(t_philo));
        if (!prog->philo_array[count]) {
            printf("Failed to allocate memory for t_philo structure\n");
            break;
        }
		count++;
	}
	prog->forks = malloc(sizeof (int) * prog->number_of_philosophers);
	if(!prog->forks)
		exit(EXIT_FAILURE);
    if (argv[2])
        prog->time_to_die = ph_atoi(argv[2]);
    if (argv[3])
        prog->time_to_eat = ph_atoi(argv[3]);
    if (argv[4])
        prog->time_to_sleep = ph_atoi(argv[4]);
    if (argv[5])
        prog->number_times_eat = ph_atoi(argv[5]);
}

int eating(t_philo *philo)
{
	return (1);
}

void sleeping(t_philo *philo)
{
	printf("%d is sleeping"philo->philo_index + 1);
	usleep(philo->prog_info->time_to_sleep);
}

void thinking(t_philo *philo)
{
	printf("%d is sleeping", philo->philo_index + 1);


}

void* philo_routine(void *philo_data) 
{
	t_philo *philo = (t_philo *)philo_data;
	
	while (philo->prog_info->death_flag == 0)
	{
		if (!eating(philo))
		{ 
			philo->time_last_ate = gettimeofday();
		}
		else if (!sleeping(philo))
		{ 
			philo->time_last_slept = gettimeofday();
		}
		else
			thinking(philo);


	}
	pthread_exit(NULL);
}

void make_threads(t_prog *prog)
{
	int t_count;
	t_count = 0;
	while (t_count < prog->number_of_philosophers)
	{
		prog->philo_array[t_count]->philo_index = t_count;
		prog->philo_array[t_count]->prog_info = prog;
		sleep(3);
		if (pthread_create(&prog->philo_array[t_count]->thread, NULL, philo_routine, (void *) prog->philo_array[t_count]) != 0)
      	{
		  	printf("Failed to create the thread\n");
			break ;
		}
		t_count++;
	}
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
	printf("initilaize struct started\n");
    if (!process_argv(argv, argc))
        initialize_struct(argv, &prog);
	// start thread/program here
	printf("initilaize struct complete\n");
	make_threads(&prog);
	count = prog.number_of_philosophers - 1;
	while (count >= 0)
	{
    	pthread_join(prog.philo_array[count]->thread, NULL);
		printf("joining thread %d\n", count);
		count--;
	}
	clean_up(&prog);
    return (0);
}
