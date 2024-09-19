/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:47:16 by nazemzam          #+#    #+#             */
/*   Updated: 2024/09/18 15:36:18 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define MAX_PHILO 300

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <pthread.h>

typedef struct s_philo
{
    pthread_t       thread;
    int             id;
    int             eating;
    int             eaten_meals;
    size_t          last_meal;
    size_t          time_to_die;
    size_t          time_to_eat;
    size_t          time_to_sleep;
    size_t          start_time;
    int             num_philos;
    int             num_times_to_eat;
    int             *dead;
}       t_philo;

typedef struct s_program
{
    int             dead_flag;
    pthread_mutex_t dead_lock;
    pthread_mutex_t meal_lock;
    pthread_mutex_t write_lock;
    t_philo         *philos;
}       t_program;

//main
int check_args(char **av);
int main(int ac, char **av);

//utils
int	ft_atoi(char *str);

//initial
get_init(t_program *program, t_philo *philo);


#endif