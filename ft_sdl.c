/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 09:47:15 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/31 17:07:51 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_sdl_init(t_fill *fill)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	fill->sdl.window = SDL_CreateWindow("FILL ME", 100, 100, 10, 10,
			SDL_WINDOW_OPENGL);
	fill->sdl.renderer = SDL_CreateRenderer(fill->sdl.window, -1,
			SDL_RENDERER_ACCELERATED);
}

void	ft_sdl_render(t_fill *fill)
{
	SDL_SetWindowSize(fill->sdl.window, fill->size_map_x * 10,
			fill->size_map_y * 10 + 30);
	SDL_RenderCopy(fill->sdl.renderer, fill->sdl.message, NULL,
			&(fill->sdl.message_rect));
	if (fill->flag != 0)
		SDL_RenderPresent(fill->sdl.renderer);
	else
		fill->flag = 1;
	SDL_SetRenderDrawColor(fill->sdl.renderer, 0, 0, 0, 255);
	SDL_RenderClear(fill->sdl.renderer);
}

void	ft_sdl_text(t_fill *fill)
{
	SDL_Color red;
	SDL_Color green;

	red.r = 255;
	red.g = 0;
	red.b = 0;
	green.r = 0;
	green.g = 255;
	green.b = 0;
	fill->sdl.font = TTF_OpenFont("../font/OpenSans-Italic.ttf", 22);
	fill->sdl.surface_message = TTF_RenderText_Solid(fill->sdl.font,
			(fill->letter == 'O') ? " Player 1 - RED" : " Player 2 - GREEN",
			(fill->letter == 'O') ? red : green);
	fill->sdl.message = SDL_CreateTextureFromSurface(fill->sdl.renderer,
			fill->sdl.surface_message);
	fill->sdl.message_rect.x = 0;
	fill->sdl.message_rect.y = 0;
	fill->sdl.message_rect.w = 170;
	fill->sdl.message_rect.h = 30;
}

int		ft_sdl_destroy(t_fill *fill)
{
	SDL_DestroyRenderer(fill->sdl.renderer);
	SDL_DestroyWindow(fill->sdl.window);
	SDL_Quit();
	return (0);
}
