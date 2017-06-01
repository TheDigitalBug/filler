/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 09:52:48 by kkotliar          #+#    #+#             */
/*   Updated: 2016/11/30 13:27:11 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*s;
	char		*d;

	i = 0;
	d = dst;
	s = src;
	if (d < s)
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	else
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	return (dst);
}
