/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:16:20 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/01 09:46:42 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int k;

	i = 0;
	while (big[i] != '\0')
	{
		k = 0;
		while (little[k] == big[i + k] && little[k] != '\0')
			k++;
		if (little[k] == '\0')
			return ((char *)(big + i));
		i++;
	}
	if ((big[0] == '\0') && (little[0] == '\0'))
		return ((char *)(big));
	return (NULL);
}
