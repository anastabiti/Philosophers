/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:19:28 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/08 09:05:44 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	struct s_ph		*ph_s;
	int				philo_nbrs;

	if (ft_check_args(av, ac) == 0)
	{
		return (0);
	}
	philo_nbrs = ft_atoi(av[1]);
	if (philo_nbrs > 200 || philo_nbrs < 1)
	{
		printf(" ERROR! PLEAS CHECK PROGRAM ARGS \n");
		return (0);
	}
	ph_s = malloc(sizeof(struct s_ph) * philo_nbrs);
	if (!ft_init(ac, av, ph_s, philo_nbrs))
	{
		free(ph_s);
		free(ph_s->chopsticks);
		return (0);
	}
	ft_threads(ph_s, philo_nbrs);
	free(ph_s);
	return (0);
}
