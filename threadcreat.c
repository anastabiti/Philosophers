/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadcreat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 08:15:16 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/08 09:06:08 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_threads_join_check_d(struct s_ph *ph_s, int philo_nbrs)
{
	int	i;

	if (check_death_meals(ph_s, philo_nbrs, ph_s[0].ac_nb) == 0)
	{
		pthread_mutex_lock(ph_s->printer);
		free(ph_s->chopsticks);
		return (0);
	}
	i = 0;
	while (i < philo_nbrs)
	{
		if (pthread_join(ph_s[i].ph_thread, NULL) != 0)
		{
			printf("Joining a thread has failed\n");
			free(ph_s->chopsticks);
			free(ph_s);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_threads(struct s_ph *ph_s, int philo_nbrs)
{
	int	i;

	i = 0;
	while (i < philo_nbrs)
	{
		ph_s[i].start = t_mills();
		ph_s[i].dying_time = t_mills() + ph_s[i].t_to_die;
		if (pthread_create(&ph_s[i].ph_thread, NULL, function, &ph_s[i]) != 0)
		{
			printf("Create a new thread has failed\n");
			free(ph_s->chopsticks);
			free(ph_s);
			return (0);
		}
		usleep(150);
		i++;
	}
	if (ft_threads_join_check_d(ph_s, philo_nbrs) == 0)
	{
		return (0);
	}
	return (1);
}
