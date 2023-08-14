/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:25:39 by pmagalha          #+#    #+#             */
/*   Updated: 2023/07/31 15:40:13 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_move_up(t_game *game, int enemies, int *x, int *y)
{
	if (game->map[y[enemies] - 1][x[enemies]] == '1' || game->map[y[enemies]
		- 1][x[enemies]] == 'C' || game->map[y[enemies] - 1][x[enemies]] == 'E'
		|| game->map[y[enemies] - 1][x[enemies]] == 'X')
		return ;
	game->map[y[enemies]][x[enemies]] = '0';
	enemy_up(game, enemies);
	game->map[y[enemies]][x[enemies]] = 'X';
}

void	enemy_move_down(t_game *game, int enemies, int *x, int *y)
{
	if (game->map[y[enemies] + 1][x[enemies]] == '1' || game->map[y[enemies]
		+ 1][x[enemies]] == 'C' || game->map[y[enemies] + 1][x[enemies]] == 'E'
		|| game->map[y[enemies] + 1][x[enemies]] == 'X')
		return ;
	game->map[y[enemies]][x[enemies]] = '0';
	enemy_down(game, enemies);
	game->map[y[enemies]][x[enemies]] = 'X';
}

void	enemy_move_right(t_game *game, int enemies, int *x, int *y)
{
	if (game->map[y[enemies]][x[enemies] + 1] == '1'
		|| game->map[y[enemies]][x[enemies] + 1] == 'C'
		|| game->map[y[enemies]][x[enemies] + 1] == 'E'
		|| game->map[y[enemies]][x[enemies] + 1] == 'X')
		return ;
	game->map[y[enemies]][x[enemies]] = '0';
	enemy_right(game, enemies);
	game->map[y[enemies]][x[enemies]] = 'X';
}

void	enemy_move_left(t_game *game, int enemies, int *x, int *y)
{
	if (game->map[y[enemies]][x[enemies] - 1] == '1'
		|| game->map[y[enemies]][x[enemies] - 1] == 'C'
		|| game->map[y[enemies]][x[enemies] - 1] == 'E'
		|| game->map[y[enemies]][x[enemies] - 1] == 'X')
		return ;
	game->map[y[enemies]][x[enemies]] = '0';
	enemy_left(game, enemies);
	game->map[y[enemies]][x[enemies]] = 'X';
}

void	move_enemy(t_game *game, int enemies)
{
	int	*x;
	int	*y;
	int	n;

	x = game->enemy_x;
	y = game->enemy_y;
	n = (rand() % 4) + 1;
	if (n == 1)
		enemy_move_up(game, enemies, x, y);
	if (n == 2)
		enemy_move_down(game, enemies, x, y);
	if (n == 3)
		enemy_move_right(game, enemies, x, y);
	if (n == 4)
		enemy_move_left(game, enemies, x, y);
	if (x[enemies] == game->player.x && y[enemies] == game->player.y)
		kill_player(game);
}
