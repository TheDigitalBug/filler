/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:56:36 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/07 13:16:00 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_count_length(long n)
{
	int i;

	i = 0;
	if (n < 0)
		i = 1;
	while ((n / 10) != 0)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static char	*ft_write_res(char *str, long nbr, long tmpnb, int i)
{
	int		k;
	char	buf[11];

	k = 0;
	while (nbr / 10 > 0)
	{
		buf[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	buf[i] = nbr % 10 + '0';
	if ((tmpnb < 0) && (buf[i] != '0'))
	{
		i++;
		buf[i] = '-';
	}
	while (i >= 0)
	{
		str[k] = buf[i];
		k++;
		i--;
	}
	str[k] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	tmpnb;
	long	nbr;

	i = 0;
	tmpnb = n;
	nbr = n;
	str = (char *)malloc(sizeof(*str) * ft_count_length(nbr) + 1);
	if (str == NULL)
		return (NULL);
	if (tmpnb < 0)
		nbr = -nbr;
	ft_write_res(str, nbr, tmpnb, i);
	return (str);
}
