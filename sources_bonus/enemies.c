/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:44:41 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/03 16:39:27 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	validate_enemies(t_game *game)
{
	if (!game->enemy_x || !game->enemy_y)
	{
		if (game->enemy_x)
			free(game->enemy_x);
		if (game->enemy_y)
			free(game->enemy_y);
		return (1);
	}
	return (0);
}

static int	count_zeros(t_game *game)
{
	int	zeros;
	int	x;
	int	y;

	zeros = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '0')
				zeros++;
		}
	}
	return (zeros);
}

int	init_enemy(t_game *game)
{
	int	x;
	int	y;
	int	enemies;

	game->enemies = count_zeros(game) / 20;
	game->enemy_x = ft_calloc(game->enemies, sizeof(int));
	game->enemy_y = ft_calloc(game->enemies, sizeof(int));
	if (validate_enemies(game))
		return (1);
	enemies = game->enemies;
	while (--enemies >= 0)
	{
		x = 0;
		y = 0;
		while (game->map[y][x] != '0')
		{
			x = rand() % (game->cols - 1);
			y = rand() % (game->rows - 1);
		}
		game->enemy_x[enemies] = x;
		game->enemy_y[enemies] = y;
	}
	return (0);
}

void	render_enemy(t_game *game)
{
	int	e;

	e = 0;
	while (e < game->enemies)
	{
		put_tile(game, "./textures/enemydown.xpm", game->enemy_x[e] * 64,
			game->enemy_y[e] * 64);
		game->map[game->enemy_y[e]][game->enemy_x[e]] = 'X';
		e++;
	}
}

void	enemy_pos(t_game *game, int moves)
{
	int	enemies;
	int	stuck;

	enemies = game->enemies;
	while (--enemies >= 0 && moves < game->movements)
	{
		while (moveability(game, game->enemy_x[enemies],
				game->enemy_y[enemies]))
		{
			enemies--;
			if (enemies < 0)
				return ;
		}
		stuck = game->enemy_x[enemies] + game->enemy_y[enemies];
		move_enemy(game, enemies);
		if (stuck == game->enemy_x[enemies] + game->enemy_y[enemies])
			enemies++;
	}
}
