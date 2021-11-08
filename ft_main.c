/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:04:29 by irodrigo          #+#    #+#             */
/*   Updated: 2021/11/08 13:27:07 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_philo.h"

/*
** TODO
** Probar a pasar la estructura inicial como variable en vez de puntero
*/
int	main(int argc, char **argv)
{
	t_envr	*my_envr;
	int		status;

	my_envr = ft_calloc(1, sizeof(t_envr));
	status = ft_check(argc, argv, my_envr);
	if (status > 0)
	{
		ft_run_threads(my_envr);

		
		//ft_total_clean(my_envr);
		return (0);
	}
	else
	{
		ft_total_clean(my_envr);
		return (-1);
	}
	//system("leaks philo");
}

void	*ft_run_threads(t_envr *my_envr)
{
	int		x;
	t_philo	*philos;

	x = 0;
	my_envr->init_time = my_gettime();
	philos = malloc(sizeof(t_philo) * my_envr->n_philos);
	bzero (philos, sizeof(t_philo) * my_envr->n_philos);
	if (!philos)
		return (NULL);
	ft_init_philos(philos, my_envr);
	//pthread_mutex_lock(my_envr->mt_control); // no hace falta bloquear si join ejecutor
	while (my_envr->n_philos > x)
		ft_exec_philo(philos, x++, my_envr);
	x = 0;
	while (my_envr->n_philos > x)
	{
		printf("esperando proceso %i\n", x);
		pthread_join(philos[x++].primary, NULL);
	}

	//pthread_mutex_lock(my_envr->mt_control);
	// ft_life(philos);
	ft_philos_clean(my_envr, philos);
	return (NULL);
}

void	ft_init_philos(t_philo *philos, t_envr *my_envr)
{
	int	x;

	my_envr->mt_fork_stat = malloc(sizeof (pthread_mutex_t)
			* my_envr->n_philos);
	if (!my_envr->mt_fork_stat)
		return ;
	x = 0;
	while (x < my_envr->n_philos)
	{
		if (x == 0)
			philos[x].left = &my_envr->mt_fork_stat[my_envr->n_philos - 1];
		else
			philos[x].left = &my_envr->mt_fork_stat[x - 1];
		philos[x].right = &my_envr->mt_fork_stat[x];
		pthread_mutex_init(&my_envr->mt_fork_stat[x], NULL);
		x++;
	}
	my_envr->mt_control = malloc(sizeof (pthread_mutex_t) * 1);
	my_envr->mt_state = malloc(sizeof (pthread_mutex_t) * 1);
	my_envr->mt_datamsg = malloc(sizeof(pthread_mutex_t) * 1);
	my_envr->mt_print = malloc(sizeof(pthread_mutex_t) * 1);
	if (!my_envr->mt_control || !my_envr->mt_state || !my_envr->mt_datamsg)
		return ;
	pthread_mutex_init(my_envr->mt_control, NULL);
	pthread_mutex_init(my_envr->mt_state, NULL);
	pthread_mutex_init(my_envr->mt_datamsg, NULL);
	pthread_mutex_init(my_envr->mt_print, NULL);
}
