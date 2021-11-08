/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:07:11 by irodrigo          #+#    #+#             */
/*   Updated: 2021/11/08 12:07:14 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_atoi(const char *str)
{
	int	nb;

	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if (*str)
		return (0);
	return (nb);
}

long int	ft_nb_size(long int n)
{
	long int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i *= 10;
	}
	return (i);
}

void	ft_write_phil_st(int work, t_philo *my_philo)
{
	int	num;

	pthread_mutex_lock(my_philo->my_env->mt_print);
	num = (my_philo->my_env)->lim_meat;
	if (work == END)
	{
		printf ("%s %d", EAT02, num);
		ft_rounds(num);
	}
	else
	{
		printf ("[%lu] ", (my_gettime() - (my_philo->my_env)->init_time));
		printf ("%s%d", GEN01, my_philo->pos);
		if (work == TAKE_FORK)
			printf ("%s", FORK01);
		if (work == EAT)
			printf ("%s %d time\n", EAT01, my_philo->meal_num);
		if (work == SLEEP)
			printf ("%s", SLEEP01);
		if (work == THINK)
			printf ("%s", THINK01);
		if (work == DEAD)
			printf ("%s", DIED01);
	}
	pthread_mutex_unlock(my_philo->my_env->mt_print);
}

void	ft_rounds(int num)
{
	if (num == 1)
		printf (" %s", GEN02);
	else
		printf (" %s", GEN03);
}
