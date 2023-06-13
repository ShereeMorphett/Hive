/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:37:55 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/13 10:10:07 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *monitoring(void *prog_data)
{
    t_prog *prog = (t_prog *)prog_data;
    int counter;
    int check;

    check = 0;
    while (check == 0)
    {
        counter = 0;
        while (counter != prog->number_of_philos)
        {
            if ((get_time() - prog->philo_array[counter]->time_last_ate) > prog->time_to_die)
            {
                pthread_mutex_lock(&prog->death_mutex);
                prog->death_flag = 1;
                printer(prog->philo_array[counter], "has died.\n");
                pthread_mutex_unlock(&prog->death_mutex);
                check = 1;
            }
            counter++;
        }
    }
	return NULL;
}

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

void	printer(t_philo *philo, char *print) // might need a mutex to stop printing after someone else has died
{
	long int	time;

	time = get_time() - philo->prog_info->start_time;
	pthread_mutex_lock(&philo->prog_info->death_mutex);
	if (philo->prog_info->death_flag == 0)
		printf("%lld %d %s", get_time() - philo->prog_info->start_time, philo->philo_index + 1, print);
	pthread_mutex_unlock(&philo->prog_info->death_mutex);
}
