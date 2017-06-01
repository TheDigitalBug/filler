/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:05:38 by kkotliar          #+#    #+#             */
/*   Updated: 2017/05/31 17:03:43 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdlib.h>
# include <unistd.h>
# include <SDL2/SDL.h>
# include <SDL2_ttf/SDL_ttf.h>
# include "libft/libft.h"
# define SUCCESS 1
# define FAIL 0

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		e;
	TTF_Font		*font;
	SDL_Rect		message_rect;
	SDL_Surface		*surface_message;
	SDL_Texture		*message;
}					t_sdl;

typedef struct		s_fill
{
	int				min;
	int				x_min;
	int				y_min;
	char			letter;
	int				x;
	int				y;
	char			**map;
	int				size_map_x;
	int				size_map_y;
	char			**piece;
	int				size_piece_x;
	int				size_piece_y;
	int				flag;
	t_sdl			sdl;

}					t_fill;
int					ft_run_over_map(t_fill *fill);
int					ft_put_piece(t_fill *fill, int x, int y);
void				ft_cheak_piece_distanse_to_enemy(t_fill *fill);
int					ft_free(t_fill *fill);
void				ft_read_map(t_fill *fill, char *line);
void				ft_read_player(t_fill *fill, char *line);
void				ft_read_piece(t_fill *fill, char *line);
void				ft_cheak_piece_distanse_to_enemy(t_fill *fill);
int					ft_put_result(t_fill *fill);
void				ft_draw_square(t_fill *fill, int x, int y);
void				ft_sdl_init(t_fill *fill);
void				ft_sdl_render(t_fill *fill);
int					ft_sdl_destroy(t_fill *fill);
void				ft_sdl_text(t_fill *fill);
#endif
