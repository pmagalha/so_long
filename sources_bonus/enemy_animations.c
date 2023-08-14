/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:01:44 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/03 14:19:02 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_up(t_game *game, int enemies)
{
	int	floor;

	floor = game->enemy_y[enemies];
	put_tile(game, "./textures/flr.xpm", game->enemy_x[enemies] * 64,
		floor * 64);
	game->enemy_y[enemies] -= 1;
	put_tile(game, "./textures/enemyup.xpm", game->enemy_x[enemies] * 64,
		game->enemy_y[enemies] * 64 + ((64 / 3) * 2));
	put_tile(game, "./textures/flr.xpm", game->enemy_x[enemies] * 64,
		floor * 64);
	usleep(70000);
	put_tile(game, "./textures/enemyup.xpm", game->enemy_x[enemies] * 64,
		game->enemy_y[enemies] * 64 + (64 / 3));
	put_tile(game, "./textures/flr.xpm", game->enemy_x[enemies] * 64,
		floor * 64);
	usleep(70000);
	put_tile(game, "./textures/enemydown.xpm", game->enemy_x[enemies] * 64,
		game->enemy_y[enemies] * 64);
	put_tile(game, "./textures/flr.xpm", game->enemy_x[enemies] * 64,
		floor * 64);
}

void	enemy_down(t_game *game, int enemies)
{
	int	floor;

	floor = game->enemy_y[enemies];
	put_tile(game, "./textures/flr.xpm", game->enemy_x[enemies] * 64,
		floor * 64);
	game->enemy_y[enemies] += 1;
	put_tile(game, "./textures/enemydown.xpm", game->enemy_x[enemies] * 64,
		game->enemy_y[enemies] * 64 - ((64 / 3) * 2));
	put_tile(game, "./textures/flr.xpm", game->enemy_x[enemies] * 64,
		floor * 64);
	usleep(70000);
	put_tile(game, "./textures/enemyup.xpm", game->enemy_x[enemies] * 64,
		game->enemy_y[enemies] * 64 - (64 / 3));
	put_tile(game, "./textures/flr.xpm", game->enemy_x[enemies] * 64,
		floor * 64);
	usleep(70000);
	put_tile(game, "./textures/enemydown.xpm", game->enemy_x[enemies] * 64,
		game->enemy_y[enemies] * 64);
	put_tile(game, "./textures/flr.xpm", game->enemy_x[enemies] * 64,
		floor * 64);
}

void	enemy_right(t_game *game, int enemies)
{
	int	floor;

	floor = game->enemy_x[enemies];
	put_tile(game, "./textures/flr.xpm", floor * 64,
		game->enemy_y[enemies] * 64);
	game->enemy_x[enemies] += 1;
	put_tile(game, "./textures/enemyright.xpm", game->enemy_x[enemies] * 64
		- ((64 / 3) * 2), game->enemy_y[enemies] * 64);
	put_tile(game, "./textures/flr.xpm", floor * 64,
		game->enemy_y[enemies] * 64);
	usleep(70000);
	put_tile(game, "./textures/enemyup.xpm", game->enemy_x[enemies] * 64
		- ((64 / 3)), game->enemy_y[enemies] * 64);
	put_tile(game, "./textures/flr.xpm", floor * 64,
		game->enemy_y[enemies] * 64);
	usleep(70000);
	put_tile(game, "./textures/enemyright.xpm", game->enemy_x[enemies] * 64,
		game->enemy_y[enemies] * 64);
	put_tile(game, "./textures/flr.xpm", floor * 64,
		game->enemy_y[enemies] * 64);
}

void	enemy_left(t_game *game, int enemies)
{
	int	floor;

	floor = game->enemy_x[enemies];
	put_tile(game, "./textures/flr.xpm", floor * 64,
		game->enemy_y[enemies] * 64);
	game->enemy_x[enemies] -= 1;
	put_tile(game, "./textures/enemyup.xpm", game->enemy_x[enemies] * 64
		+ ((64 / 3) * 2), game->enemy_y[enemies] * 64);
	put_tile(game, "./textures/flr.xpm", floor * 64,
		game->enemy_y[enemies] * 64);
	usleep(70000);
	put_tile(game, "./textures/enemyup.xpm", game->enemy_x[enemies] * 64
		+ ((64 / 3)), game->enemy_y[enemies] * 64);
	put_tile(game, "./textures/flr.xpm", floor * 64,
		game->enemy_y[enemies] * 64);
	usleep(70000);
	put_tile(game, "./textures/enemyleft.xpm", game->enemy_x[enemies] * 64,
		game->enemy_y[enemies] * 64);
	put_tile(game, "./textures/flr.xpm", floor * 64,
		game->enemy_y[enemies] * 64);
}

int	moveability(t_game *game, int x, int y)
{
	if (game->map[y + 1][x] == '0')
		return (0);
	if (game->map[y - 1][x] == '0')
		return (0);
	if (game->map[y][x + 1] == '0')
		return (0);
	if (game->map[y][x - 1] == '0')
		return (0);
	return (1);
}
