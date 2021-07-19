/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <rvena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:02:42 by rvena             #+#    #+#             */
/*   Updated: 2021/07/16 19:06:08 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	gettime(void)
{
	struct timeval		tme;
	unsigned long long	tii;

	gettimeofday(&tme, NULL);
	tii = (tme.tv_usec / 1000) + (tme.tv_sec * 1000);
	return (tii);
}
