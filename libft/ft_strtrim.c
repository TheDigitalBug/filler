/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:10:25 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/07 15:20:06 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ret(int k, int i, const char *s, char *tmp)
{
	int j;

	j = 0;
	if (i == 0)
	{
		tmp[0] = '\0';
		return (tmp);
	}
	while (k <= i)
	{
		tmp[j] = s[k];
		j++;
		k++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char		*ft_strtrim(char const *s)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	while ((s[i] == ' ') || (s[i] == '	') || (s[i] == '\n'))
		i++;
	k = i;
	while (s[i] != '\0')
		i++;
	i--;
	while (((s[i] == ' ') || (s[i] == '	') || (s[i] == '\n')) && i != 0)
		i--;
	if (i == 0)
		k = i;
	tmp = (char *)malloc(sizeof(*tmp) * (i + 1 - k) + 1);
	if (tmp == NULL)
		return (NULL);
	ft_ret(k, i, s, tmp);
	return (tmp);
}
