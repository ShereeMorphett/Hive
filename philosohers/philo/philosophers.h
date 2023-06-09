/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:37:55 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/09 14:52:39 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#	define PHILOSOPHERS_H
#	include <stdio.h>
#	include <pthread.h>
#	include <stdlib.h> 
#	include <unistd.h>
#	include <sys/time.h>

typedef struct s_prog t_prog; // Forward declaration of t_prog struct

typedef struct s_philo
{

	pthread_t thread;
	int philo_index;
	int	time_last_ate;
	t_prog	*prog_info;
	
	/*
	this will have all the last eaten data etc
	potentially hold own threads and use that to send
	*/
}	t_philo;

typedef struct s_prog
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_times_eat;
	t_philo **philo_array;
	long long start_time;
	int death_flag;
	int times_eaten;
	pthread_mutex_t *forks; //potentially
	pthread_mutex_t death_mutex;
	pthread_mutex_t hordor;

}	t_prog;

int initialize_struct(char **argv, t_prog *prog);
void	printer(t_philo *philo, char *print);
long long	get_time(void);
void	non_usleep(int ms);
int	process_argv(char *argv[], int argc);
int	ph_atoi(const char *str);
#endif