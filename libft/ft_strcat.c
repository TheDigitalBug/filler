/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:39:12 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/01 09:43:41 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char		*dest;
	const char	*str2;
	int			i;
	int			k;

	i = 0;
	k = 0;
	dest = s1;
	str2 = s2;
	while (dest[i] != '\0')
		i++;
	while (str2[k] != '\0')
	{
		dest[i] = str2[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (s1);
}
