/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:37:55 by smorphet          #+#    #+#             */
/*   Updated: 2023/05/26 14:41:00 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#	define PHILOSOPHERS_H
#	include <stdio.h>
#	include <pthread.h>
#	include <stdlib.h> 

typedef struct struct_philo
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_times_eat;
	// array of philosophers
}	t_philo;

int	process_argv(char *argv[], int argc);
int	ph_atoi(const char *str);

#endif