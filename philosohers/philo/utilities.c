/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:58:28 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/21 10:01:07 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	non_usleep(int ms)
{
	long int	time;

	time = get_time();
	while (get_time() - time < ms)
		usleep(500);
}

int	ft_pthread_exit(t_prog *prog)
{
	int	count;

	count = prog->number_of_philos - 1;
	while (count >= 0)
	{
		pthread_join(prog->philo_array[count]->thread, NULL);
		count--;
	}
	return (SUCCESS);
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
