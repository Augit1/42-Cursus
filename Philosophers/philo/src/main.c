/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:58:40 by aude-la-          #+#    #+#             */
/*   Updated: 2024/09/23 11:36:39 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	need_to_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_state(TAKE_FORK, philo);
	pthread_mutex_lock(philo->right_fork);
	print_state(TAKE_FORK, philo);
	pthread_mutex_lock(&data->last_meal_mtx);
	philo->last_meal = running_time(data);
	pthread_mutex_unlock(&data->last_meal_mtx);
	print_state(IS_EATING, philo);
	if (precise_sleep(philo, data->eat_time))
		return (unlock_forks(philo));
	unlock_forks(philo);
	pthread_mutex_lock(&data->last_meal_mtx);
	if (++philo->nb_of_meal == data->nb_of_eat_required)
		return (pthread_mutex_unlock(&data->last_meal_mtx), 1);
	pthread_mutex_unlock(&data->last_meal_mtx);
	return (0);
}

void	*philolife(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(&data->last_meal_mtx);
	philo->last_meal = data->start_time;
	pthread_mutex_unlock(&data->last_meal_mtx);
	while (get_current_timestamp() < data->start_time)
		usleep(20);
	if (philo->id % 2)
		usleep(1000);
	while (1)
	{
		if (dead_check(philo))
			return (NULL);
		print_state(IS_THINKING, philo);
		if (need_to_eat(data, philo))
			return (NULL);
		print_state(IS_SLEEPING, philo);
		if (precise_sleep(philo, data->sleep_time))
			return (NULL);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data			data;
	int				i;

	if (args_init(argc, argv, &data) != 0)
		return (ERROR);
	if (init(&data) != 0)
		return (ERROR);
	if (init_threads(&data) != 0)
		return (ERROR);
	i = -1;
	while (++i < data.nb_of_philo)
		pthread_mutex_destroy(&data.forks[i]);
	pthread_mutex_destroy(&data.last_meal_mtx);
	pthread_mutex_destroy(&data.is_dead);
	free(data.forks);
	free(data.philo);
	return (0);
}
