/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:29:52 by aude-la-          #+#    #+#             */
/*   Updated: 2024/07/03 17:44:52 by aude-la-         ###   ########.fr       */
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

int	dead_check(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (data->nb_of_philo < 2)
	{
		printf(COLOR_DIED "%ld %d died\n" COLOR_RESET,
			running_time(data), philo->id);
		return (1);
	}
	else if (philo->last_meal < (running_time(data) - data->die_time))
	{
		sem_wait(data->is_died);
		printf(COLOR_DIED "%ld %d died\n" COLOR_RESET,
			running_time(data), philo->id);
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
