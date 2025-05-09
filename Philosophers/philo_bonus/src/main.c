/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:58:40 by aude-la-          #+#    #+#             */
/*   Updated: 2024/09/12 17:10:01 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	need_to_eat(t_data *data, t_philo *philo)
{
	if (philo->id % 2)
		usleep(1000);
	sem_wait(data->forks);
	sem_wait(data->forks);
	if (dead_check(philo))
		return (unlock_forks(data));
	sem_wait(data->last_meal_sem);
	philo->last_meal = running_time(data);
	sem_post(data->last_meal_sem);
	print_state(IS_EATING, philo);
	if (precise_sleep(philo, data->eat_time))
		return (unlock_forks(data));
	unlock_forks(data);
	if (++philo->nb_of_meal == data->nb_of_eat_required)
		return (1);
	return (0);
}

void	philolife(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	while (1)
	{
		if (dead_check(philo))
			break ;
		print_state(IS_THINKING, philo);
		if (need_to_eat(data, philo))
			break ;
		print_state(IS_SLEEPING, philo);
		if (precise_sleep(philo, data->sleep_time))
			break ;
	}
	if (philo->nb_of_meal == data->nb_of_eat_required)
		exit(3);
	exit(4);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (args_init(argc, argv, &data) != 0)
		return (ERROR);
	if (init(&data) != 0)
		return (ERROR);
	if (init_process(&data) != 0)
		return (ERROR);
	wait_philo(&data);
	clean_semaphores(&data);
	if (data.philo)
		free(data.philo);
	data.philo = NULL;
	return (0);
}
