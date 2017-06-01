/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 10:34:52 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/06 12:57:56 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int		ft_base(char tmp)
{
	static char	b[16] = "0123456789ABCDEF";
	int			j;

	j = 0;
	while (j <= 15)
	{
		if (tmp == b[j])
			break ;
		j++;
	}
	return (j);
}

static void		ft_down_let(char *tmp, const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			tmp[i] = str[i] - 32;
		else
			(tmp[i] = str[i]);
		i++;
	}
}

static int		ft_strleng(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int				ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		minus;
	int		nb;
	char	*tmp;

	minus = 1;
	nb = 0;
	i = ft_strleng(str);
	tmp = (char*)malloc(sizeof(*tmp) * i);
	ft_down_let(tmp, str);
	i = 0;
	while (tmp[i] == ' ' || tmp[i] == '	' || tmp[i] == '\n')
		i++;
	if (tmp[i] == '-' && ((tmp[i + 1] >= 'A' && tmp[i + 1] <= 'F') ||
				(tmp[i + 1] >= '0' && tmp[i + 1] <= '9')))
	{
		minus = -1;
		i++;
	}
	while (((tmp[i] >= 'A' && tmp[i] <= 'F') ||
				(tmp[i] >= '0' && tmp[i] <= '9')))
		nb = nb * str_base + ft_base(tmp[i++]);
	free(tmp);
	return (minus * nb);
}
