/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:37:49 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/06 17:10:38 by smorphet         ###   ########.fr       */
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

static void initialize_struct(char **argv, t_philo *philo) 
{
    if (argv[1] && (philo->number_of_philosophers = ph_atoi(argv[1])) == 0) {
        printf("Number of philosophers must be more than 0\n");
        exit(0);
    }
	philo->t_array = malloc(sizeof (pthread_t) * philo->number_of_philosophers);
	if(!philo->t_array)
		exit(EXIT_FAILURE);
	philo->forks = malloc(sizeof (int) * philo->number_of_philosophers);
	if(!philo->forks)
		exit(EXIT_FAILURE);
    if (argv[2])
        philo->time_to_die = ph_atoi(argv[2]);
    if (argv[3])
        philo->time_to_eat = ph_atoi(argv[3]);
    if (argv[4])
        philo->time_to_sleep = ph_atoi(argv[4]);
    if (argv[5])
        philo->number_times_eat = ph_atoi(argv[5]);
}


void* philo_routine(void *arg) 
{
	pthread_mutex_t hold;

	pthread_mutex_init(&hold, NULL);
	printf("This is %p printing\n", arg);
	printf("This is after sleep\n");
	pthread_exit(NULL);
}


void make_threads(t_philo *philo)
{
	int t_count;
	t_count = 0;
	while (t_count < philo->number_of_philosophers)
	{
		if (pthread_create(&philo->t_array[t_count], NULL, philo_routine, (void *) philo->t_array) != 0)
      	{
		  	printf("Failed to create the thread\n");
			break ;
		}
	  printf("thread %d has started\n", t_count);
      t_count++;
	}
}
void clean_up(t_philo *philo)
{
	if (philo->t_array)
		free(philo->t_array);
	if (philo->forks)
		free(philo->forks);
}

int main(int argc, char **argv)
{
    t_philo philo;
	int count;
    
	if (argc != 5 && argc != 6) {
        printf("Incorrect number of arguments: ");
        printf("number_of_philosophers, time_to_die, time_to_eat, time_to_sleep. ");
        printf("Optional: number_of_times_each_philosopher_must_eat\n");
        return (0);
    }
    if (!process_argv(argv, argc))
        initialize_struct(argv, &philo);
	// start thread/program here
	make_threads(&philo);
	count = philo.number_of_philosophers;
	while (count >= 0)
	{
    	pthread_join(philo.t_array[count], NULL);
		printf("joining thread %d\n", count);
		count--;
	}

	clean_up(&philo);
    return (0);
}
