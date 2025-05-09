/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:26:03 by aude-la-          #+#    #+#             */
/*   Updated: 2024/09/18 13:42:09 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_init(int argc, char **argv, t_data *data)
{
	if (check_args(argc, argv))
		return (ERROR);
	data->nb_of_philo = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_of_eat_required = ft_atoi(argv[5]);
	else
		data->nb_of_eat_required = -1;
	if (data->nb_of_eat_required == 0)
		return (printf("Error: nb of eat can't be 0\n"), ERROR);
	return (0);
}

int	init(t_data *data)
{
	int	i;

	data->philo = malloc(data->nb_of_philo * sizeof(t_philo));
	if (!data->philo)
		return (ERROR);
	data->forks = malloc(data->nb_of_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (ERROR);
	pthread_mutex_init(&data->is_dead, NULL);
	data->dead = 0;
	i = -1;
	while (++i < data->nb_of_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		data->philo[i].id = i + 1;
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->nb_of_philo];
		data->philo[i].last_meal = get_current_timestamp();
		data->philo[i].nb_of_meal = 0;
		data->philo[i].data = data;
	}
	return (0);
}

void	*monitor_function(t_data *data)
{
	int		i;

	while (1)
	{
		i = -1;
		while (++i < data->nb_of_philo)
			if (dead_check(&data->philo[i]))
				return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	init_threads(t_data *data)
{
	int			i;

	pthread_mutex_init(&data->last_meal_mtx, NULL);
	data->start_time = get_current_timestamp() + (data->nb_of_philo * 100);
	i = -1;
	while (++i < data->nb_of_philo)
		if (pthread_create(&data->philo[i].thread,
				NULL, philolife, &data->philo[i]) != 0)
			return (1);
	monitor_function(data);
	i = -1;
	while (++i < data->nb_of_philo)
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (1);
	return (0);
}
