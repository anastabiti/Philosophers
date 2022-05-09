/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:58:45 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/08 09:08:04 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_args(char **av, int ac)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (ac == 5 || ac == 6)
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				{
					printf("ERROR : ARGS must be numbers only!\n");
					return (0);
				}
				j++;
			}
			i++;
		}
		return (1);
	}
	printf("ERROR!\n");
	return (0);
}

int	meals(struct s_ph *ph_s, int num_philo)
{
	int	x;
	int	ret;

	ret = 0;
	x = 0;
	while (x < num_philo)
	{
		if (ph_s[x].eated >= ph_s->meals)
		{
			ret++;
		}
		x++;
	}
	if (ret >= num_philo)
	{
		ph_s->is_dead = 1;
		return (0);
	}
	else
		return (1);
}

int	ft_check_min(struct s_ph *ph_s)
{
	if (ph_s[0].t_to_die < 60 || ph_s[0].t_to_eat < 60
		|| ph_s[0].t_to_sleep < 60 || ph_s->meals <= 0)
	{
		printf(" ERROR! PLEAS CHECK PROGRAM ARGS \n");
		return (0);
	}
	return (1);
}

int	check_death_meals(struct s_ph *ph_s, int philo_nbrs, int ac)
{
	if (ac == 6)
	{
		while (1)
		{
			if (!meals(ph_s, philo_nbrs) || !ft_death(ph_s, philo_nbrs))
				return (0);
		}
	}
	if (ac == 5)
	{
		while (1)
		{
			if (!ft_death(ph_s, philo_nbrs))
			{
				return (0);
			}
		}
	}
	return (0);
}

int	ft_death(struct s_ph *ph_s, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		if (t_mills() > ph_s[i].dying_time)
		{
			pthread_mutex_lock(ph_s->printer);
			printf("\033[0;31m [%lld] Philo %d  died\n",
				(t_mills() - ph_s->start), ph_s[i].philo_id);
			ph_s[i].is_dead = 1;
			return (0);
		}
		i++;
	}
	return (1);
}
