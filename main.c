/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:25:15 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/31 17:06:20 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_free(t_fill *fill)
{
	int y;

	y = 0;
	while (y < fill->size_map_y)
	{
		free(fill->map[y]);
		y++;
	}
	free(fill->map);
	y = 0;
	while (y < fill->size_piece_y)
	{
		free(fill->piece[y]);
		y++;
	}
	free(fill->piece);
	return (FAIL);
}

void	ft_draw_square(t_fill *fill, int x, int y)
{
	SDL_Rect	rect;

	rect.x = x * 10;
	rect.y = y * 10 + 30;
	rect.w = 9;
	rect.h = 9;
	if (fill->map[y][x] == 'O')
		SDL_SetRenderDrawColor(fill->sdl.renderer, 255, 0, 0, 255);
	else if (fill->map[y][x] == 'X')
		SDL_SetRenderDrawColor(fill->sdl.renderer, 0, 255, 0, 255);
	else if (fill->map[y][x] == '.')
		SDL_SetRenderDrawColor(fill->sdl.renderer, 50, 50, 50, 255);
	if (fill->letter == fill->map[y][x])
		SDL_RenderFillRect(fill->sdl.renderer, &rect);
	SDL_RenderDrawRect(fill->sdl.renderer, &rect);
}

int		main(void)
{
	char	*line;
	t_fill	*fill;

	line = NULL;
	if (!(fill = (t_fill*)malloc(sizeof(t_fill))))
		return (0);
	ft_sdl_init(fill);
	ft_read_player(fill, line);
	while (1)
	{
		while (SDL_PollEvent(&(fill->sdl.e)))
			if (fill->sdl.e.type == SDL_QUIT ||
					fill->sdl.e.key.keysym.sym == SDLK_ESCAPE)
				return (0);
		ft_read_map(fill, line);
		ft_read_piece(fill, line);
		if (ft_run_over_map(fill) == FAIL)
			return (ft_sdl_destroy(fill));
		ft_sdl_render(fill);
		ft_free(fill);
	}
	ft_sdl_destroy(fill);
	return (1);
}
