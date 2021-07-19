/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <rvena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:41:11 by rvena             #+#    #+#             */
/*   Updated: 2021/07/19 20:14:52 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	mutex_init(t_str *g_ever)
{
	int	j;

	j = 0;
	while (j < g_ever->number_of_philo)
	{
		pthread_mutex_init(&g_ever->phil[j].mutex, NULL);
		j++;
	}
}

static int	set_values(int argc, char **argv, t_str *g_ever)
{
	g_ever->number_of_philo = ft_atoi(argv[1]);
	g_ever->time_to_die = ft_atoi(argv[2]);
	g_ever->time_to_eat = ft_atoi(argv[3]);
	g_ever->time_to_sleep = ft_atoi(argv[4]);
	g_ever->is_dead = 0;
	g_ever->required_num_eat = -1;
	if (argc == 6)
	{
		g_ever->required_num_eat = ft_atoi(argv[5]);
		if (g_ever->required_num_eat < 1)
		{
			write(1, "Bad arguments\n", 14);
			return (1);
		}
	}
	g_ever->phil = malloc(sizeof(t_phil) * g_ever->number_of_philo);
	if (g_ever->number_of_philo < 1 || g_ever->time_to_die < 1
		|| g_ever->time_to_eat < 1 || g_ever->required_num_eat == 0
		|| g_ever->time_to_sleep < 1 || !g_ever->phil)
	{
		write(1, "Bad arguments\n", 14);
		return (1);
	}
	return (0);
}

int	init_struct(int argc, char **argv, t_str *g_ever)
{
	if (argc >= 5 && argc <= 6)
	{
		if (set_values(argc, argv, g_ever) == 1)
			return (1);
		mutex_init(g_ever);
		pthread_mutex_init(&g_ever->lock, NULL);
		pthread_mutex_init(&g_ever->print, NULL);
	}
	else
	{
		write(1, "Bad number of arguments\n", 25);
		return (1);
	}
	return (0);
}
