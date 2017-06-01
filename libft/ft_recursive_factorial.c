/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 10:32:53 by kkotliar          #+#    #+#             */
/*   Updated: 2016/10/29 17:04:04 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_recursive_factorial(int nb)
{
	int a;

	if (nb < 0 || nb > 13)
		return (0);
	if (nb == 0)
		return (1);
	a = nb * ft_recursive_factorial(nb - 1);
	return (a);
}
