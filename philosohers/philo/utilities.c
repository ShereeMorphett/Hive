#include "philosophers.h"

void monitoring(t_prog *prog)
{
    int counter;
    int check;
	int full;
    check = 0;
    non_usleep(0.7 * prog->time_to_die);
    while (check == 0)
    {
		counter = 0;
		full = 0;
		// while(prog->number_times_eat  >= 0 && counter != prog->number_of_philos) //THIS NEEDS TO BE ADDED INTO
		// {
		// 	if (prog->philo_array[counter]->eaten_count >= prog->number_times_eat)
		// 		full++
		// 	if ()
		// }
        counter = 0;
		while (counter != prog->number_of_philos)
        {
            if ((get_time() - prog->philo_array[counter]->time_last_ate) > prog->time_to_die)
            {
                printer(prog->philo_array[counter], "has died.\n");
                prog->death_flag = 1;
                check = 1;
				pthread_mutex_unlock(&prog->forks[prog->philo_array[counter]->fork_r]);
				pthread_mutex_unlock(&prog->forks[prog->philo_array[counter]->fork_r]);
				pthread_exit(NULL);
            }
            counter++;
        }
    }
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
