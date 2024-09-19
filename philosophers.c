/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:56 by nazemzam          #+#    #+#             */
/*   Updated: 2024/09/12 16:11:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int check_args(char **av)
{
    if(ft_atoi(av[1]) > MAX_PHILO || ft_atoi(av[1]) <= 0 || is_num(av[1]) == 1)
        return (write(2, "INVALID PHILOSOPHERS NUMBER\n", 28), 1);
    if (ft_atoi(av[2]) <= 0 || is_num(av[2]) == 1)
        return (write(2, "INVALID TIME TO DIE\n", 20), 1);
    if (ft_atoi(av[3]) <= 0 || is_num(av[3]) == 1)
        return (write(2, "INVALID TIME TO EAT\n", 20), 1);
    if (ft_atoi(av[4]) <= 0 || is_num(av[4]) == 1)
        return (write(2, "INVALID TIME TO SLEEP\n", 22), 1);
    return (0);
}

int main(int ac, char **av)
{
    t_program       program;
    t_philo         philo[MAX_PHILO];
    pthread_mutex_t fork[MAX_PHILO];
    
    if (ac != 5 && ac != 6)
        return (write(2, "WRONG ARGUMENTS NUMBER\n", 22), 1);
    if (check_args(av) == 1)
        return (1);
    get_init(&program, philo);
}