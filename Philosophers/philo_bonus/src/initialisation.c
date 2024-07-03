/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:26:03 by aude-la-          #+#    #+#             */
/*   Updated: 2024/07/03 16:50:57 by aude-la-         ###   ########.fr       */
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
	return (0);
}

int	init(t_data *data)
{
	int	i;

	clean_semaphores(data);
	data->philo = malloc(data->nb_of_philo * sizeof(t_philo));
	if (!data->philo)
		return (ERROR);
	data->forks = sem_open("/forks", O_CREAT, 0644, data->nb_of_philo);
	if (data->forks == SEM_FAILED)
		return (ERROR);
	data->is_died = sem_open("/is_died", O_CREAT, 0644, 1);
	if (data->is_died == SEM_FAILED)
		return (ERROR);
	data->last_meal_sem = sem_open("/last_meal_sem", O_CREAT, 0644, 1);
	if (data->last_meal_sem == SEM_FAILED)
		return (ERROR);
	i = -1;
	while (++i < data->nb_of_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].last_meal = get_current_timestamp();
		data->philo[i].nb_of_meal = 0;
		data->philo[i].data = data;
	}
	return (0);
}

int	init_process(t_data *data)
{
	int	i;

	data->start_time = get_current_timestamp();
	i = -1;
	while (++i < data->nb_of_philo)
	{
		data->philo[i].pid = fork();
		if (data->philo[i].pid == 0)
		{
			philolife(&data->philo[i]);
			exit(0);
		}
		else if (data->philo[i].pid < 0)
			return (ERROR);
	}
	return (0);
}

void	wait_philo(t_data *data)
{
	int	i;
	int	wstatus;

	i = -1;
	waitpid(-1, &wstatus, 0);
	if (WIFEXITED(wstatus))
	{
		if (WEXITSTATUS(wstatus) == 4)
		{
			while (++i < data->nb_of_philo)
				kill(data->philo[i].pid, SIGTERM);
			sem_post(data->is_died);
		}
	}
}

void	clean_semaphores(t_data *data)
{
	sem_close(data->forks);
	sem_unlink("/forks");
	sem_close(data->is_died);
	sem_unlink("/is_died");
	sem_close(data->last_meal_sem);
	sem_unlink("/last_meal_sem");
}
