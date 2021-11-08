/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:34:10 by irodrigo          #+#    #+#             */
/*   Updated: 2021/09/24 12:56:03 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	pos;

	pos = 0;
	while (str[pos] != '\0')
		pos++;
	return (pos);
}