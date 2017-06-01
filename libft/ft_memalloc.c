/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:17:28 by kkotliar          #+#    #+#             */
/*   Updated: 2016/12/05 13:52:56 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*mem;
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	mem = (void *)malloc(sizeof(void *) * size);
	if (mem == NULL)
		return (NULL);
	tmp = mem;
	while (i < size)
	{
		tmp[i] = '\0';
		i++;
	}
	return (mem);
}
