/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <rvena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:01:39 by rvena             #+#    #+#             */
/*   Updated: 2021/07/19 20:28:58 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>

	// int					pos;
	// int					fork;
typedef struct s_phil
{
	int					is_eat;
	int					num;
	int					alive;
	unsigned long long	time_start;
	unsigned long long	lst_eat;
	unsigned long long	jst_eat;
	int					num_eat;
	pthread_t			thread;
	pthread_mutex_t		mutex;
}	t_phil;

typedef struct s_str
{
	t_phil				*phil;
	pthread_mutex_t		*fork;
	pthread_mutex_t		lock;
	pthread_mutex_t		print;
	size_t				prm[5];
	int					number_of_eats;
	int					ret;
	int					stt;
	unsigned long long	forks;
	int					number_of_philo;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_die;
	unsigned long long	time_to_sleep;
	int					required_num_eat;
	int					is_dead;
}	t_str;

unsigned long long	gettime(void);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *src);
void				ft_write(char *str, int num);
int					init_struct(int argc, char **argv, t_str *g_ever);
void				write_time(unsigned long long time);
int					check_death(int num);
void				write_time(unsigned long long time);
void				sft_write(char *str, int num);
void				get_forks(int num, int prev);
int					check_life_of_philo(void);
void				*ft_philo(void *i);
void				ft_pthread_create(void);
t_str	g_ever;

#endif