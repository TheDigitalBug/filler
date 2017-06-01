/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_over_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:15:35 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/31 10:59:06 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_cheak_piece_distanse_to_enemy(t_fill *fill)
{
	int x;
	int y;

	y = 0;
	while (y < fill->size_map_y)
	{
		x = 0;
		while (x < fill->size_map_x)
		{
			if (fill->map[y][x] == (fill->letter == 'O' ? 'X' : 'O') &&
					fill->min > abs(x - fill->x) + abs(y - fill->y))
			{
				fill->x_min = fill->x;
				fill->y_min = fill->y;
				fill->min = abs(x - fill->x) + abs(y - fill->y);
			}
			x++;
		}
		y++;
	}
}

int		ft_put_piece(t_fill *fill, int x, int y)
{
	int	xp;
	int	yp;
	int	inter;

	inter = 0;
	yp = 0;
	while (yp < fill->size_piece_y)
	{
		xp = 0;
		while (xp < fill->size_piece_x)
		{
			if (fill->map[y + yp][x + xp] + fill->piece[yp][xp] == 167)
				return (0);
			if ((fill->map[y + yp][x + xp] + fill->piece[yp][xp] == 176) ||
				(fill->map[y + yp][x + xp] + fill->piece[yp][xp] == 158))
				inter++;
			xp++;
		}
		yp++;
	}
	if (inter != 1)
		return (0);
	fill->x = x;
	fill->y = y;
	return (1);
}

int		ft_put_result(t_fill *fill)
{
	ft_putnbr_fd(fill->y_min, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(fill->x_min, 1);
	ft_putchar_fd('\n', 1);
	return (SUCCESS);
}

int		ft_run_over_map(t_fill *fill)
{
	int x;
	int y;

	fill->min = fill->size_map_x + 1 + fill->size_map_y + 1;
	fill->x = -1;
	fill->y = -1;
	y = 0;
	while (y < fill->size_map_y - fill->size_piece_y + 1)
	{
		x = 0;
		while (x < fill->size_map_x - fill->size_piece_x + 1)
		{
			if (ft_put_piece(fill, x, y) == 1)
				ft_cheak_piece_distanse_to_enemy(fill);
			x++;
		}
		y++;
	}
	if (fill->min != (fill->size_map_y + 1 + fill->size_map_x + 1))
		return (ft_put_result(fill));
	else
		return (ft_free(fill));
}
