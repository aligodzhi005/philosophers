/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_life_of_philo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <rvena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:51:15 by rvena             #+#    #+#             */
/*   Updated: 2021/07/19 20:14:22 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_life_of_philo(void)
{
	int					j;
	unsigned long long	time;
	int					num;

	num = g_ever.required_num_eat * g_ever.number_of_philo;
	j = 0;
	g_ever.number_of_eats = 0;
	while (j < g_ever.number_of_philo)
	{
		time = gettime();
		g_ever.number_of_eats += g_ever.phil[j].num_eat;
		if (g_ever.number_of_eats == num)
			return (1);
		if (g_ever.is_dead == 0 && check_death(j))
		{
			g_ever.is_dead = 1;
			return (1);
		}
		j++;
	}
	return (0);
}
