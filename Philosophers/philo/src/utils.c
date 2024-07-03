/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:29:52 by aude-la-          #+#    #+#             */
/*   Updated: 2024/07/03 17:41:37 by aude-la-         ###   ########.fr       */
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
		printf(COLOR_DIED "\n%ld %d died\n" COLOR_RESET,
			running_time(data), philo->id);
		return (1);
	}
	pthread_mutex_lock(&data->is_died);
	if (data->dead)
	{
		pthread_mutex_unlock(&data->is_died);
		return (1);
	}
	else if (philo->last_meal < running_time(data) - data->die_time)
	{
		data->dead = 1;
		printf(COLOR_DIED "\n%ld %d died\n" COLOR_RESET,
			running_time(data), philo->id);
		pthread_mutex_unlock(&data->is_died);
		return (1);
	}
	pthread_mutex_unlock(&data->is_died);
	return (0);
}

int	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}
