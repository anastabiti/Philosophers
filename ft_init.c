/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:49:04 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/07 13:01:39 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_next(int ac, char **av, struct s_ph *ph_s, int philo_nbrs)
{
	int	i;

	i = 0;
	while (i < philo_nbrs && (ac == 5 || ac == 6))
	{
		ph_s[i].philo_nbrs = philo_nbrs;
		ph_s[i].eated = 0;
		ph_s[i].is_dead = 0;
		ph_s[i].t_to_die = ft_atoi(av[2]);
		ph_s[i].t_to_eat = ft_atoi(av[3]);
		ph_s[i].t_to_sleep = ft_atoi(av[4]);
		ph_s[i].meals = 1;
		if (ac == 6)
		{
			ph_s[i].meals = ft_atoi(av[5]);
		}
		ph_s[0].ac_nb = ac;
		ph_s[i].right = i;
		ph_s[i].philo_id = i + 1;
		ph_s[i].left = ((i + 1) % ph_s[0].philo_nbrs);
		i++;
	}
}

int	ft_init(int ac, char **av, struct s_ph *ph_s, int philo_nbrs)
{
	pthread_mutex_t			printer;
	int						i;

	i = 0;
	ph_s->chopsticks = malloc(sizeof(pthread_mutex_t) * philo_nbrs);
	if (pthread_mutex_init(&printer, NULL) != 0)
	{
		printf("Mutex Initializing failed\n");
		return (0);
	}
	while (i < philo_nbrs)
	{
		if (pthread_mutex_init(&(ph_s->chopsticks[i]), NULL) != 0)
		{
			printf("Mutex Initializing failed\n");
			return (0);
		}
		ph_s[i].chopsticks = ph_s->chopsticks;
		ph_s[i].printer = &printer;
		i++;
	}
	ft_next(ac, av, ph_s, philo_nbrs);
	if (!ft_check_min(ph_s))
		return (0);
	return (1);
}
