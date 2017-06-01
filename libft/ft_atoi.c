/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:05:44 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/01 10:31:40 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int minus;
	int nb;

	i = 0;
	nb = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
		i++;
	if ((str[i] == '-') && (str[i + 1] >= '0') && (str[i + 1] <= '9'))
	{
		i++;
		minus = -1;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (10 * nb) + (str[i] - '0');
		i++;
	}
	return (nb * minus);
}
