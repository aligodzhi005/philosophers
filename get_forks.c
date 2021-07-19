/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <rvena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:37:45 by rvena             #+#    #+#             */
/*   Updated: 2021/07/19 20:14:26 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_forks(int num, int prev)
{
	pthread_mutex_lock(&g_ever.lock);
	pthread_mutex_lock(&g_ever.phil[prev].mutex);
	ft_write("take a left fork\n", (num + 1));
	pthread_mutex_lock(&g_ever.phil[num].mutex);
	ft_write("take a right fork\n", (num + 1));
	pthread_mutex_unlock(&g_ever.lock);
}
