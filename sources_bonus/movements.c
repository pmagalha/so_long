/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:07:04 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/01 15:14:41 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	win_condition(t_game *game)
{
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->collected++;
		game->map[game->player.y][game->player.x] = '0';
	}
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collected != game->collectibles)
	{
		return ;
	}
	if (game->map[game->player.y][game->player.x] == 'X')
		kill_player(game);
}

void	move_up(t_game *game)
{
	int	tile;
	int	grass;

	grass = game->player.y;
	tile = game->player.y - 1;
	game->player.y = tile;
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collectibles == game->collected)
	{
		exit_open(game);
		put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
		exit_anim(game);
	}
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
		put_tile(game, "./textures/mcu1.xpm", game->player.x * 64, tile * 64);
		put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
		eat_animation(game);
	}
	else
		move_up_aux(game, grass, tile);
	render_moves_counter(game);
	win_condition(game);
}

void	move_down(t_game *game)
{
	int	tile;
	int	grass;

	grass = game->player.y;
	tile = game->player.y + 1;
	game->player.y = tile;
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collectibles == game->collected)
	{
		exit_open(game);
		put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
		exit_anim(game);
	}
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
		put_tile(game, "./textures/mcd1.xpm", game->player.x * 64, tile * 64);
		put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
		eat_animation(game);
	}
	else
		move_down_aux(game, grass, tile);
	render_moves_counter(game);
	win_condition(game);
}

void	move_left(t_game *game)
{
	int	tile;
	int	grass;

	grass = game->player.x;
	tile = game->player.x - 1;
	game->player.x = tile;
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collectibles == game->collected)
	{
		exit_open(game);
		put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
		exit_anim(game);
	}
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
		put_tile(game, "./textures/mcl1.xpm", tile * 64, game->player.y * 64);
		put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
		eat_animation(game);
	}
	else
		move_left_aux(game, grass, tile);
	render_moves_counter(game);
	win_condition(game);
}

void	move_right(t_game *game)
{
	int	tile;
	int	grass;

	grass = game->player.x;
	tile = game->player.x + 1;
	game->player.x = tile;
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collectibles == game->collected)
	{
		exit_open(game);
		put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
		exit_anim(game);
	}
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
		put_tile(game, "./textures/mcr1.xpm", tile * 64, game->player.y * 64);
		put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
		eat_animation(game);
	}
	else
		move_right_aux(game, grass, tile);
	render_moves_counter(game);
	win_condition(game);
}
