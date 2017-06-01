/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:44:18 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/01 19:09:59 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_ret(char const *s1, char const *s2, char *tmp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tmp[i] = s2[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if ((!s1) || (!s2))
		return (0);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	tmp = (char *)malloc(sizeof(*tmp) * (j + i) + 1);
	if (tmp == NULL)
		return (NULL);
	ft_ret(s1, s2, tmp);
	return (tmp);
}
