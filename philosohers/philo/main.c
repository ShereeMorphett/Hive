/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:37:49 by smorphet          #+#    #+#             */
/*   Updated: 2023/05/26 14:39:27 by smorphet         ###   ########.fr       */
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

static void initialize_struct(char **argv, t_philo *philo) {
    if (argv[1] && (philo->number_of_philosophers = ph_atoi(argv[1])) == 0) {
        printf("Number of philosophers must be more than 0\n");
        exit(0);
    }
    if (argv[2])
        philo->time_to_die = ph_atoi(argv[2]);
    if (argv[3])
        philo->time_to_eat = ph_atoi(argv[3]);
    if (argv[4])
        philo->time_to_sleep = ph_atoi(argv[4]);
    if (argv[5])
        philo->number_times_eat = ph_atoi(argv[5]);
}

void* printThread(int id) {
    (void)id;
    printf("This is a thread printing\n");
    // Exit the thread
	pthread_exit(NULL);
}

int main(int argc, char **argv) {
    t_philo philo;
    pthread_t thread;

    if (argc != 5 && argc != 6) {
        printf("Incorrect number of arguments: ");
        printf("number_of_philosophers, time_to_die, time_to_eat, time_to_sleep. ");
        printf("Optional: number_of_times_each_philosopher_must_eat\n");
        return (0);
    }
    if (!process_argv(argv, argc))
        initialize_struct(argv, &philo);
    
	// Create the thread, this needs to become its own function that takes program
	//state and makes a loop to create array of thread ids
	//move struct into id too
    if (pthread_create(&thread, NULL, printThread, NULL) != 0) {
        printf("Failed to create the thread\n");
        return 1;
	}
	// Create the thread, this needs to become its own function that takes program
	//when array is done i need to work out how the hell you make the usleep and stuff print
	// then we can also play the stupid bit where sheree works out how they share 
	// the forks etc and choose to eat....so you know the actual point of the task.
	
    pthread_join(thread, NULL);
    return 0;
}
