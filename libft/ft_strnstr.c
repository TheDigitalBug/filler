/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:02:22 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/01 09:45:00 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t k;

	i = 0;
	while ((big[i] != '\0') && (i < len))
	{
		k = 0;
		while (little[k] == big[i + k] && little[k] != '\0' && (i + k < len))
			k++;
		if (little[k] == '\0')
			return ((char *)(big + i));
		i++;
	}
	if ((big[0] == '\0') && (little[0] == '\0'))
		return ((char *)(big));
	return (NULL);
}
