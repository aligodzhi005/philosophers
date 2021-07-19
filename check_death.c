/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <rvena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:34:26 by rvena             #+#    #+#             */
/*   Updated: 2021/07/19 20:14:44 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(int num)
{
	unsigned long long	time;

	time = gettime() - g_ever.phil[num].lst_eat;
	if (time > (unsigned long long)g_ever.time_to_die)
	{
		pthread_mutex_lock(&g_ever.print);
		write_time(gettime());
		write(1, " ", 1);
		write_time((unsigned long long)num + 1);
		write(1, " ", 1);
		write(1, "died\n", 5);
		g_ever.is_dead = 1;
		return (1);
	}
	return (0);
}
