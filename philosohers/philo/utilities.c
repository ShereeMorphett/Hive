/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:37:55 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/09 14:38:43 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	if (philo->prog_info->death_flag == 0)
		printf("%lld %d %s", get_time() - philo->prog_info->start_time, philo->philo_index + 1, print);
}
