/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <rvena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:35:42 by rvena             #+#    #+#             */
/*   Updated: 2021/07/19 19:36:09 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_time(unsigned long long time)
{
	int		num;
	char	*res;

	num = time % 10;
	res = malloc(sizeof(int));
	*res = num + 48;
	if (time > 9)
		write_time(time / 10);
	write(1, res, 1);
	free(res);
}

void	ft_write(char *str, int num)
{
	pthread_mutex_lock(&g_ever.print);
	write_time(gettime());
	write(1, " ", 1);
	write_time((unsigned long long)num);
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&g_ever.print);
}
