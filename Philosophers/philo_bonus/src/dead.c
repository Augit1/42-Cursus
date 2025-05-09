/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:40:24 by aude-la-          #+#    #+#             */
/*   Updated: 2024/09/12 12:54:53 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_check(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (data->nb_of_philo < 2)
	{
		data->start_time = get_current_timestamp();
		return (print_state(IS_DEAD, philo), 1);
	}
	else if (philo->last_meal < running_time(data) - data->die_time)
		return (print_state(IS_DEAD, philo), 1);
	return (0);
}
