/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:57:07 by kkotliar          #+#    #+#             */
/*   Updated: 2017/02/02 18:38:10 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_removeline(long i, char *tmp)
{
	long j;

	j = 0;
	if (tmp[i] == '\0')
	{
		free(tmp);
		tmp = NULL;
		return (tmp);
	}
	while (tmp[i] != '\0')
	{
		tmp[j] = tmp[i];
		i++;
		j++;
	}
	while (j < i)
	{
		tmp[j] = '\0';
		j++;
	}
	return (tmp);
}

static char		*ft_strcatination(char *tmp, char *buf)
{
	long	a[2];
	char	*new_tmp;

	a[1] = 0;
	a[0] = 0;
	if (tmp != NULL)
		while (tmp[a[0]])
			a[0]++;
	while (buf[a[1]] != '\0')
		a[1]++;
	if (!(new_tmp = (char *)malloc(sizeof(*new_tmp) * (a[0] + a[1] + 1))))
		return (NULL);
	a[0] = 0;
	a[1] = 0;
	if (tmp != NULL)
		while (tmp[a[0]] != '\0')
		{
			new_tmp[a[0]] = tmp[a[0]];
			a[0]++;
		}
	while (buf[a[1]] != '\0')
		new_tmp[a[0]++] = buf[a[1]++];
	new_tmp[a[0]] = '\0';
	free(tmp);
	return (new_tmp);
}

static int		ft_sendline(char **tmp, char **line)
{
	long i;

	i = 0;
	while ((((*tmp)[i]) != '\n') && (((*tmp)[i]) != '\0'))
		i++;
	if ((*tmp)[i] == '\n')
	{
		(*tmp)[i] = '\0';
		*line = ft_strdup(*tmp);
		*tmp = ft_removeline(i + 1, *tmp);
		return (1);
	}
	return (0);
}

static int		ft_returneof(long ret, char **tmp, char **line)
{
	if (ret < 0)
	{
		*line = NULL;
		return (-1);
	}
	if (*tmp != NULL)
	{
		*line = ft_strdup(*tmp);
		*tmp = NULL;
		return (1);
	}
	*line = NULL;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	long		ret;
	char		buf[BUFF_SIZE];
	static char	**tmp;

	if ((read(fd, buf, 0) == -1) || (fd < 0) || (!line))
		return (-1);
	if (tmp == NULL)
		if (!(tmp = (char **)malloc(sizeof(*tmp) * (FD))))
			return (-1);
	if (tmp[fd] != NULL)
		if (ft_sendline(&tmp[fd], line) == 1)
			return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp[fd] = ft_strcatination(tmp[fd], buf);
		if (ft_sendline(&tmp[fd], line) == 1)
			return (1);
	}
	if (ft_returneof(ret, &tmp[fd], line) == 1)
		return (1);
	if (ft_returneof(ret, &tmp[fd], line) == -1)
		return (-1);
	return (0);
}
