/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:58:28 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/20 17:18:50 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
static void check_death(t_prog *prog, int counter)
{
		if ((get_time() - prog->philo_array[counter]->time_last_ate) >= (long)prog->time_to_die)
	{
		printer(prog->philo_array[counter], "has died\n");
		prog->death_flag = 1;
		pthread_mutex_unlock(&prog->forks[prog->philo_array[counter]->fork_l]);
		pthread_mutex_unlock(&prog->forks[prog->philo_array[counter]->fork_r]);
		pthread_exit(NULL);
	}
}
void monitoring(t_prog *prog)
{
    int counter;
	int full;
	
	full = 0;
    non_usleep(0.7 * prog->time_to_die);
    while (1)
    {
		counter = 0;
		if (prog->number_times_eat > 0)
			are_they_full(prog);
		while (counter != prog->number_of_philos)
        {
			check_death(prog, counter);
            counter++;
        }
    }
}

void	non_usleep(int ms)
{
	long int	time;

	time = get_time();
	while (get_time() - time < ms)
		usleep(500);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (unsigned long)1000) + tv.tv_usec / 1000);
}

void	printer(t_philo *philo, char *print)
{
	long long int	time;

	time = get_time() - philo->prog_info->start_time;
	pthread_mutex_lock(&philo->prog_info->death_mutex);
	if (philo->prog_info->death_flag == 0)
		printf("%lld %d %s", time, philo->philo_index + 1, print);
	pthread_mutex_unlock(&philo->prog_info->death_mutex);
}
