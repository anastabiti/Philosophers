/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:20:23 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/07 09:12:02 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

struct s_ph
{
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	long long int		start;
	int					meals;
	int					eated;
	int					philo_nbrs;
	int					philo_id;
	int					left;
	int					right;
	int					is_dead;
	long long int		dying_time;
	int					ac_nb;
	pthread_t			ph_thread;
	pthread_mutex_t		fork_mutex;
	pthread_mutex_t		*chopsticks;
	pthread_mutex_t		*printer;
};

int							ft_atoi(const char *str);
long long int				t_mills(void);
int							ft_threads(struct s_ph *inside, int philo_nbrs);
int							ft_death(struct s_ph *long_s, int philo_nbrs);
int							ft_check_args(char **av, int ac);
int							ft_init(int ac, char **av,
								struct s_ph *s_t, int phs);
void						ft_create_thread(struct s_ph *a);
void						*function(void *ptr);
void						ft_take_forks(struct s_ph *inside);
void						ft_sleep(struct s_ph *inside);
void						ft_next(int ac,
								char **av, struct s_ph *long_s, int phs);
int							meals(struct s_ph *inside, int phs);
int							ft_check_min(struct s_ph *long_s);
int							check_death_meals(
								struct s_ph *long_s, int philo_nbrs, int ac);
#endif