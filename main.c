/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <rvena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:01:20 by rvena             #+#    #+#             */
/*   Updated: 2021/07/28 03:16:14 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main(int argc, char **argv)
{	
	if (init_struct(argc, argv, &g_ever))
		return (1);
	ft_pthread_create();
	usleep(15000);
	while (1)
	{
		if (check_life_of_philo() == 1)
			return (0);
	}
}
