/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypresses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:36:18 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/09 15:40:01 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_keypress(int keysym, t_game *game)
{
	int	moves;

	moves = game->movements;
	if (keysym == XK_Escape)
		free_all(game);
	if (keysym == XK_w || keysym == XK_Up)
		w_conditions(game);
	if (keysym == XK_s || keysym == XK_Down)
		s_conditions(game);
	if (keysym == XK_a || keysym == XK_Left)
		a_conditions(game);
	if (keysym == XK_d || keysym == XK_Right)
		d_conditions(game);
	enemy_pos(game, moves);
	return (0);
}

void	w_conditions(t_game *game)
{
	t_point	p;
	int		x;
	int		y;

	x = 0;
	y = 0;
	p = game->player;
	if (game->map[p.y - 1][p.x] == '1')
		return ;
	if (game->map[p.y - 1][p.x] == 'E' && game->collected != game->collectibles)
		return ;
	else
		move_up(game);
	game->movements++;
}

void	s_conditions(t_game *game)
{
	t_point	p;
	int		x;
	int		y;

	x = 0;
	y = 0;
	p = game->player;
	if (game->map[p.y + 1][p.x] == 'E' && game->collected != game->collectibles)
		return ;
	if (game->map[p.y + 1][p.x] == '1')
		return ;
	else
		move_down(game);
	game->movements++;
}

void	a_conditions(t_game *game)
{
	t_point	p;
	int		x;
	int		y;

	x = 0;
	y = 0;
	p = game->player;
	if (game->map[p.y][p.x - 1] == 'E' && game->collected != game->collectibles)
		return ;
	if (game->map[p.y][p.x - 1] == '1')
		return ;
	else
		move_left(game);
	game->movements++;
}

void	d_conditions(t_game *game)
{
	t_point	p;
	int		x;
	int		y;

	x = 0;
	y = 0;
	p = game->player;
	if (game->map[p.y][p.x + 1] == 'E' && game->collected != game->collectibles)
		return ;
	if (game->map[p.y][p.x + 1] == '1')
		return ;
	else
		move_right(game);
	game->movements++;
}
