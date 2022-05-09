/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:24:39 by atabiti           #+#    #+#             */
/*   Updated: 2022/05/06 12:30:01 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	t_mills(void)
{
	struct timeval	epoch_time;

	gettimeofday(&epoch_time, NULL);
	return (epoch_time.tv_sec * 1000 + epoch_time.tv_usec / 1000);
}
