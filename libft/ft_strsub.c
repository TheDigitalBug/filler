/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:55:25 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/01 19:11:05 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	tmp = (char *)malloc(sizeof(*tmp) * len + 1);
	if (tmp == NULL)
		return (NULL);
	while (len)
	{
		tmp[i] = s[start];
		start++;
		len--;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
