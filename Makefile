# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvena <rvena@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 19:32:36 by rvena             #+#    #+#              #
#    Updated: 2021/07/19 20:28:34 by rvena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = check_death.c \
		check_life_of_philo.c \
		ft_atoi.c \
		ft_strlen.c \
		ft_write.c \
		get_forks.c \
		get_time.c \
		init_struct.c \
		main.c \
		pthread_create.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
RM = rm -rf
CFLAGS = -g -Werror -Wextra -Wall
all:	$(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
clean:		
		$(RM) $(OBJS)
fclean:		clean
		$(RM) $(NAME)
re:		fclean all 