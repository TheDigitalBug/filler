/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:39:12 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/01 19:25:15 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
		i++;
	while ((s2[k] != '\0') && (i + k + 1 < size))
	{
		s1[i + k] = s2[k];
		k++;
	}
	s1[i + k] = '\0';
	while (s2[k] != '\0')
		k++;
	if (i > size)
		i = size;
	return (k + i);
}
