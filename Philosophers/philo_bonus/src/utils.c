/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:29:52 by aude-la-          #+#    #+#             */
/*   Updated: 2024/09/12 12:12:45 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec));
}

long	running_time(t_data *data)
{
	return ((get_current_timestamp() - data->start_time) / 1000);
}

int	precise_sleep(t_philo *philo, long ms)
{
	long	start;
	long	end;

	start = get_current_timestamp();
	end = start + (ms * 1000);
	while (get_current_timestamp() < end)
	{
		usleep(200);
		if (end - get_current_timestamp())
			if (dead_check(philo))
				return (1);
	}
	return (0);
}

int	unlock_forks(t_data *data)
{
	sem_post(data->forks);
	sem_post(data->forks);
	return (1);
}

void	print_state(t_state state, t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	sem_wait(data->is_dead);
	if (state == IS_DEAD)
		printf(COLOR_DIED "\n%ld %d died\n" COLOR_RESET,
			running_time(data), philo->id);
	else if (state == IS_EATING)
		printf(COLOR_EATING "\n%ld %d is eating\n" COLOR_RESET,
			running_time(data), philo->id);
	else if (state == IS_SLEEPING)
		printf(COLOR_SLEEPING "\n%ld %d is sleeping\n" COLOR_RESET,
			running_time(data), philo->id);
	else if (state == IS_THINKING)
		printf(COLOR_THINKING "\n%ld %d is thinking\n" COLOR_RESET,
			running_time(data), philo->id);
	if (state != IS_DEAD)
		sem_post(data->is_dead);
}
