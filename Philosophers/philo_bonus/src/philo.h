/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:53 by aude-la-          #+#    #+#             */
/*   Updated: 2024/09/12 16:27:36 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ERROR -1

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/time.h>

# define COLOR_RESET   "\033[0m"
# define COLOR_THINKING "\033[1;33m"
# define COLOR_EATING   "\033[1;35m"
# define COLOR_SLEEPING "\033[1;34m"
# define COLOR_DIED	"\033[1;31m"

typedef struct s_philo
{
	int				id;
	pid_t			pid;
	long			last_meal;
	int				nb_of_meal;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int			nb_of_philo;
	int			die_time;
	int			eat_time;
	int			sleep_time;
	int			nb_of_eat_required;
	sem_t		*forks;
	t_philo		*philo;
	sem_t		*is_dead;
	sem_t		*last_meal_sem;
	long		start_time;
}				t_data;

typedef enum e_state
{
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	IS_DEAD,
}			t_state;

long	get_current_timestamp(void);
long	running_time(t_data *data);
int		precise_sleep(t_philo *philo, long ms);
int		unlock_forks(t_data *data);
int		ft_isnumber(char *s);
int		check_args(int argc, char **argv);
int		args_init(int argc, char **argv, t_data *data);
int		init(t_data *data);
int		init_process(t_data *data);
int		dead_check(t_philo *philo);
void	wait_philo(t_data *data);
void	philolife(t_philo *philo);
void	clean_semaphores(t_data *data);
void	print_state(t_state state, t_philo *philo);
int		ft_atoi(const char *str);

#endif
