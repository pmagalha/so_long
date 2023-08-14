/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:07:04 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/01 15:13:42 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collectibles == game->collected)
	{
		ft_printf("You win!");
		free_all(game);
	}
}

void	move_up(t_game *game)
{
	int	tile;
	int	grass;

	grass = game->player.y;
	tile = game->player.y - 1;
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass
		* 64);
	put_tile(game, "./textures/mcd1.xpm", game->player.x * 64, tile * 64
		+ ((64 / 3) * 2));
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass
		* 64);
	usleep(70000);
	put_tile(game, "./textures/mcd1.xpm", game->player.x * 64, tile * 64
		+ ((64 / 3)));
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass
		* 64);
	usleep(70000);
	put_tile(game, "./textures/mcd1.xpm", game->player.x * 64, tile * 64);
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass
		* 64);
	game->player.y = tile;
	win_condition(game);
}

void	move_down(t_game *game)
{
	int	tile;
	int	grass;

	grass = game->player.y;
	tile = game->player.y + 1;
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass
		* 64);
	put_tile(game, "./textures/mcd1.xpm", game->player.x * 64, tile * 64
		- ((64 / 3) * 2));
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass
		* 64);
	usleep(70000);
	put_tile(game, "./textures/mcd1.xpm", game->player.x * 64, tile * 64
		- ((64 / 3)));
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass
		* 64);
	usleep(70000);
	put_tile(game, "./textures/mcd1.xpm", game->player.x * 64, tile * 64);
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass
		* 64);
	game->player.y = tile;
	win_condition(game);
}

void	move_left(t_game *game)
{
	int	tile;
	int	grass;

	grass = game->player.x;
	tile = game->player.x - 1;
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y
		* 64);
	put_tile(game, "./textures/mcd1.xpm", tile * 64 + ((64 / 3) * 2),
		game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y
		* 64);
	usleep(70000);
	put_tile(game, "./textures/mcd1.xpm", tile * 64 + ((64 / 3)),
		game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y
		* 64);
	usleep(70000);
	put_tile(game, "./textures/mcd1.xpm", tile * 64, game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y
		* 64);
	game->player.x = tile;
	win_condition(game);
}

void	move_right(t_game *game)
{
	int	tile;
	int	grass;

	grass = game->player.x;
	tile = game->player.x + 1;
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y
		* 64);
	put_tile(game, "./textures/mcd1.xpm", tile * 64 - ((64 / 3) * 2),
		game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y
		* 64);
	usleep(70000);
	put_tile(game, "./textures/mcd1.xpm", tile * 64 - ((64 / 3)),
		game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y
		* 64);
	usleep(70000);
	put_tile(game, "./textures/mcd1.xpm", tile * 64, game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y
		* 64);
	game->player.x = tile;
	win_condition(game);
}
