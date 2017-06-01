/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:48:34 by kkotliar          #+#    #+#             */
/*   Updated: 2017/02/20 19:17:01 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			j++;
		i++;
	}
	if (s[0] == '\0')
		return (j);
	if ((j == 0) && (s[i] == '\0'))
		j++;
	return (j);
}

static int	ft_count_let_in_w(const char *s, int *i, char c)
{
	int j;

	j = 0;
	if (s[*i] == '\0')
		return (0);
	while (s[*i] != c)
	{
		(*i)++;
		j++;
		if (s[*i] == '\0')
			break ;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**tmp;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	words = ft_count_words(s, c);
	tmp = (char**)malloc(sizeof(*tmp) * words + 1);
	if (tmp == NULL)
		return (NULL);
	while (j < words)
	{
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
		tmp[j] = ft_strsub(s, i, ft_count_let_in_w(s, &i, c));
		j++;
	}
	tmp[j] = NULL;
	return (tmp);
}
