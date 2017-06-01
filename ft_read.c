/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 18:25:34 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/31 17:06:54 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_read_player(t_fill *fill, char *line)
{
	if (get_next_line(0, &line) > 0)
	{
		if (line[0] == '$')
		{
			if (line[10] == '1')
				fill->letter = 'O';
			else
				fill->letter = 'X';
			ft_sdl_text(fill);
		}
		if (line)
			free(line);
	}
	fill->flag = 0;
}

static void	ft_read_map_size(t_fill *fill, char *line)
{
	char	**tmp;

	if (get_next_line(0, &line) > 0)
		if (line[0] == 'P' && line[1] == 'l')
		{
			tmp = ft_strsplit(line, ' ');
			fill->size_map_x = ft_atoi(tmp[2]);
			fill->size_map_y = ft_atoi(tmp[1]);
			if (!(fill->map = (char**)malloc(sizeof(char*) *
							(fill->size_map_y + 1))))
				exit(0);
			free(tmp);
		}
}

void		ft_read_map(t_fill *fill, char *line)
{
	int		i;
	int		r;

	r = 0;
	ft_read_map_size(fill, line);
	(line) ? free(line) : 1;
	while (r < fill->size_map_y + 1 && get_next_line(0, &line) > 0)
	{
		if (ft_isdigit(line[0]) != 0)
		{
			i = 0;
			if (!(fill->map[r - 1] = (char*)malloc(sizeof(char) *
					(fill->size_map_x + 1))))
				exit(0);
			while (i < fill->size_map_x)
			{
				fill->map[r - 1][i] = (line[4 + i] >= 97 && line[4 + i] <= 122)
					? line[4 + i] - 32 : line[4 + i];
				ft_draw_square(fill, i, r - 1);
				i++;
			}
		}
		(line) ? free(line) : 1;
		r++;
	}
}

static void	ft_read_piece_size(t_fill *fill, char *line)
{
	char	**tmp;

	if (get_next_line(0, &line) > 0)
		if (line[0] == 'P' && line[1] == 'i')
		{
			tmp = ft_strsplit(line, ' ');
			fill->size_piece_x = ft_atoi(tmp[2]);
			fill->size_piece_y = ft_atoi(tmp[1]);
			if (!(fill->piece = (char**)malloc(sizeof(char*) *
				(fill->size_piece_y + 1))))
				exit(0);
			free(tmp);
		}
}

void		ft_read_piece(t_fill *fill, char *line)
{
	int		i;
	int		k;

	k = 0;
	ft_read_piece_size(fill, line);
	if (line)
		free(line);
	while (k < fill->size_piece_y && get_next_line(0, &line) > 0)
	{
		i = 0;
		fill->piece[k] = (char*)malloc(sizeof(char) * (fill->size_piece_x + 1));
		while (i < fill->size_piece_x)
		{
			fill->piece[k][i] = (line[i] == '*') ? fill->letter : line[i];
			i++;
		}
		k++;
		if (line)
			free(line);
	}
}
