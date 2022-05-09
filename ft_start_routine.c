/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:36:10 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/06 11:53:51 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*function(void *ptr)
{
	struct s_ph		*ph_s;
	int				i;

	ph_s = (struct s_ph *)ptr;
	if (ph_s[0].ac_nb == 6)
	{
		if (ph_s->eated >= ph_s->meals)
		{
			return (NULL);
		}
	}
	i = 0;
	while (ph_s->is_dead == 0)
	{
		printf("\033[0;37m [%lld] Philo %d  is thinking \n",
			(t_mills() - ph_s->start), ph_s->philo_id);
		ft_take_forks(ph_s);
		ft_sleep(ph_s);
	}
	return (NULL);
}

void	ft_take_forks(struct s_ph *ph_s)
{
	pthread_mutex_lock(&(ph_s->chopsticks[ph_s->right]));
	pthread_mutex_lock(ph_s->printer);
	printf("\033[0;37m [%lld] Philo %d has taken the right fork %d \n",
		(t_mills() - ph_s->start), ph_s->philo_id, ph_s->right);
	pthread_mutex_lock(&(ph_s->chopsticks[ph_s->left]));
	printf("\033[0;37m [%lld] Philo %d has taken the left fork %d \n",
		(t_mills() - ph_s->start),
		ph_s->philo_id, ph_s->left);
	ph_s->eated += 1;
	printf("\033[0;32m [%lld] Philo %d  is eating\n",
		(t_mills() - ph_s->start), ph_s->philo_id);
	ph_s->dying_time += ph_s->t_to_die;
	usleep(ph_s->t_to_eat * 1000);
	pthread_mutex_unlock(ph_s->printer);
	pthread_mutex_unlock(&(ph_s->chopsticks[ph_s->right]));
	pthread_mutex_unlock(&(ph_s->chopsticks[ph_s->left]));
}

void	ft_sleep(struct s_ph *inside)
{
	printf("\033[0;37m [%lld] Philo %d  is sleeping \n",
		(t_mills() - inside->start), inside->philo_id);
	usleep(inside->t_to_sleep * 1000);
}
