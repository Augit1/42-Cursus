/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:03:59 by aude-la-          #+#    #+#             */
/*   Updated: 2024/09/17 18:07:08 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_check(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (data->nb_of_philo < 2)
	{
		usleep(data->die_time * 1000);
		return (print_state(IS_DEAD, philo), 1);
	}
	pthread_mutex_lock(&data->is_dead);
	pthread_mutex_lock(&data->last_meal_mtx);
	if (data->dead || philo->nb_of_meal == data->nb_of_eat_required)
	{
		pthread_mutex_unlock(&data->last_meal_mtx);
		pthread_mutex_unlock(&data->is_dead);
		return (1);
	}
	pthread_mutex_unlock(&data->is_dead);
	if (philo->last_meal < running_time(data) - data->die_time)
	{
		pthread_mutex_unlock(&data->last_meal_mtx);
		return (print_state(IS_DEAD, philo), 1);
	}
	pthread_mutex_unlock(&data->last_meal_mtx);
	return (0);
}
