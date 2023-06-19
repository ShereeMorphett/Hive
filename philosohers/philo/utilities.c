/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:58:28 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/15 14:46:13 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*neater version of other one, needs testing at school*/
static void are_they_full(t_prog *prog)
{
	int full = 0;
	int count = 0;

	while (count < prog->number_of_philos)
	{
		if (prog->philo_array[count]->eaten_count >= prog->number_times_eat)
		{
			full++;
			if (full >= prog->number_of_philos)
			{
				pthread_mutex_lock(&prog->death_mutex);
				prog->death_flag = 1;
				pthread_mutex_unlock(&prog->death_mutex);
				pthread_exit(NULL);
			}
		}
		count++;
	}
}

// static void are_they_full(t_prog *prog)
// {
// 	int full;
// 	int count;

// 	count = 0;
// 	full = 0;
// 	while (prog->number_times_eat >= 0 && count != prog->number_of_philos)
// 	{
// 		if (prog->philo_array[count]->eaten_count >= prog->number_times_eat)
// 		 	full++;
// 		count++;
// 	}
// 	if (full >= prog->number_of_philos)
// 	{
// 		pthread_mutex_lock(&prog->death_mutex);
// 		prog->death_flag = 1;
// 		pthread_mutex_unlock(&prog->death_mutex);
// 		pthread_exit(NULL);
// 	}	
//  }

void monitoring(t_prog *prog)
{
    int counter;
    int check;
	int full;

    check = 0;
	full = 0;
    non_usleep(0.7 * prog->time_to_die);
    while (check == 0)
    {
		counter = 0;
		if (prog->number_times_eat < 0) //added in unchecked but should make non amount eaten faster
			are_they_full(prog);
		while (counter != prog->number_of_philos)
        {
            if ((get_time() - prog->philo_array[counter]->time_last_ate) > prog->time_to_die)
            {
                printer(prog->philo_array[counter], "has died\n");
                prog->death_flag = 1;
                check = 1;
				pthread_mutex_unlock(&prog->forks[prog->philo_array[counter]->fork_l]);
				pthread_mutex_unlock(&prog->forks[prog->philo_array[counter]->fork_r]);
				pthread_exit(NULL);
            }
            counter++;
        }
    }
}

/* potentially more accurate but is not norm compliant*/
/*void non_usleep(int ms)
{
	struct timeval start, current;
	long long target_time, elapsed;

	gettimeofday(&start, NULL);
	target_time = ms * 1000;

	do {
		gettimeofday(&current, NULL);
		elapsed = (current.tv_sec - start.tv_sec) * 1000000LL +
		          (current.tv_usec - start.tv_usec);
	} while (elapsed < target_time);
}
*/

void	non_usleep(int ms)
{
	long int	time;

	time = get_time();
	while (get_time() - time < ms)
		usleep(ms / 10);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/*this is already mutext protected area due to the mutext use in the routine function,
may not need the death mutext there, save time on printing....maybe i shouldnt use printf? change to write?
*/
void	printer(t_philo *philo, char *print)
{
	long long int	time;

	time = get_time() - philo->prog_info->start_time;
	pthread_mutex_lock(&philo->prog_info->death_mutex);
	if (philo->prog_info->death_flag == 0)
		printf("%lld %d %s", time, philo->philo_index + 1, print);
	pthread_mutex_unlock(&philo->prog_info->death_mutex);
}
