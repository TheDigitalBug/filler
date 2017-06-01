/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:43:10 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/04 13:56:09 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	rev[11];
	long	tempnb;
	long	nbr;

	tempnb = n;
	nbr = n;
	i = 0;
	if (tempnb < 0)
		nbr = -nbr;
	while ((nbr / 10) > 0)
	{
		rev[i] = nbr % 10 + '0';
		i++;
		nbr = nbr / 10;
	}
	rev[i] = nbr % 10 + '0';
	if (tempnb < 0)
		rev[++i] = '-';
	while (i >= 0)
		write(fd, &rev[i--], 1);
}
