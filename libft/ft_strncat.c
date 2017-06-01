/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:39:12 by kkotliar          #+#    #+#             */
/*   Updated: 2016/11/30 09:43:43 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*dest;
	const char	*str2;
	int			i;
	size_t		k;

	i = 0;
	k = 0;
	dest = s1;
	str2 = s2;
	while (dest[i] != '\0')
		i++;
	while ((str2[k] != '\0') && (k < n))
	{
		dest[i] = str2[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (s1);
}
