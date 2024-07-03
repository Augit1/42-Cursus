/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:53 by aude-la-          #+#    #+#             */
/*   Updated: 2024/07/03 17:38:51 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ERROR -1

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define COLOR_RESET   "\033[0m"
# define COLOR_THINKING "\033[1;33m"
# define COLOR_EATING   "\033[1;35m"
# define COLOR_SLEEPING "\033[1;34m"
# define COLOR_DIED	"\033[1;31m"

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal;
	int				nb_of_meal;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				nb_of_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				nb_of_eat_required;
	int				dead;
	pthread_mutex_t	*forks;
	t_philo			*philo;
	pthread_mutex_t	is_died;
	pthread_mutex_t	last_meal_mtx;
	long			start_time;
}				t_data;

long	get_current_timestamp(void);
long	running_time(t_data *data);
void	*philolife(void *arg);
int		precise_sleep(t_philo *philo, long ms);
int		dead_check(t_philo *philo);
int		unlock_forks(t_philo *philo);
int		ft_isnumber(char *s);
int		check_args(int argc, char **argv);
int		args_init(int argc, char **argv, t_data *data);
int		init(t_data *data);
int		init_threads(t_data *data);
int		ft_atoi(const char *str);

#endif
