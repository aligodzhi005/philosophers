/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <rvena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:58:06 by rvena             #+#    #+#             */
/*   Updated: 2021/07/19 20:25:08 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// usleep(1000 * (g_ever.time_to_eat - (gettime() - g_ever.phil[num].lst_eat)));
void	*ft_philo(void *i)
{
	int	num;
	int	prev;

	num = *(int *)i;
	if (num % 2 != 0)
		usleep(1000);
	prev = num - 1;
	if (prev < 0)
		prev = g_ever.number_of_philo - 1;
	g_ever.phil[num].lst_eat = gettime();
	while (g_ever.phil[num].num_eat != g_ever.required_num_eat)
	{
		get_forks(num, prev);
		g_ever.phil[num].lst_eat = gettime();
		ft_write("is eating\n", (num + 1));
		usleep(1000 * g_ever.time_to_eat);
		pthread_mutex_unlock(&g_ever.phil[num].mutex);
		pthread_mutex_unlock(&g_ever.phil[prev].mutex);
		g_ever.phil[num].num_eat++;
		ft_write("is sleeping\n", (num + 1));
		usleep(1000 * (g_ever.time_to_sleep - (gettime()
					- g_ever.phil[num].lst_eat - g_ever.time_to_eat)));
		ft_write("is thinking\n", num + 1);
	}
	return (i);
}

static void	create_cycle(int j)
{
	while (j < g_ever.number_of_philo)
	{
		g_ever.phil[j].num = j;
		g_ever.phil[j].lst_eat = gettime();
		g_ever.phil[j].num_eat = 0;
		pthread_create(&(g_ever.phil[j].thread), NULL, ft_philo,
			(void *)&g_ever.phil[j].num);
		j += 2;
	}
}

void	ft_pthread_create(void)
{
	int	j;

	j = 0;
	create_cycle(j);
	usleep(1);
	j = 1;
	create_cycle(j);
}
