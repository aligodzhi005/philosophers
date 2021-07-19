/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <rvena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:09:56 by rvena             #+#    #+#             */
/*   Updated: 2021/07/16 20:15:45 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *src)
{
	unsigned char	*temp_src;
	size_t			count;

	count = 0;
	temp_src = (unsigned char *)src;
	while (*temp_src != '\0')
	{
		count++;
		temp_src++;
	}
	return (count);
}
