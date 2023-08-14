/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:57:21 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/01 15:14:38 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up_aux(t_game *game, int grass, int tile)
{
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
	put_tile(game, "./textures/mcu2.xpm", game->player.x * 64, 
		tile * 64 + ((64 / 3) * 2));
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
	usleep(70000);
	put_tile(game, "./textures/mcu3.xpm", game->player.x * 64, 
		tile * 64 + ((64 / 3)));
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
	usleep(70000);
	put_tile(game, "./textures/mcu2.xpm", game->player.x * 64, tile * 64);
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
	put_tile(game, "./textures/mcu1.xpm", game->player.x * 64, tile * 64);
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
}

void	move_down_aux(t_game *game, int grass, int tile)
{
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
	put_tile(game, "./textures/mcd3.xpm", game->player.x * 64,
		tile * 64 - ((64 / 3) * 2));
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
	usleep(70000);
	put_tile(game, "./textures/mcd2.xpm", game->player.x * 64, 
		tile * 64 - ((64 / 3)));
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
	usleep(70000);
	put_tile(game, "./textures/mcd3.xpm", game->player.x * 64, tile * 64);
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
	usleep(70000);
	put_tile(game, "./textures/mcd1.xpm", game->player.x * 64, tile * 64);
	put_tile(game, "./textures/flr.xpm", game->player.x * 64, grass * 64);
}

void	move_left_aux(t_game *game, int grass, int tile)
{
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
	put_tile(game, "./textures/mcl2.xpm", tile * 64 + ((64 
				/ 3) * 2), game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
	usleep(70000);
	put_tile(game, "./textures/mcl3.xpm", tile * 64 + ((64 
				/ 3)), game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
	usleep(70000);
	put_tile(game, "./textures/mcl4.xpm", tile * 64, game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
	usleep(70000);
	put_tile(game, "./textures/mcl1.xpm", tile * 64, game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
}

void	move_right_aux(t_game *game, int grass, int tile)
{
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
	put_tile(game, "./textures/mcr2.xpm", tile * 64 - ((64 
				/ 3) * 2), game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
	usleep(70000);
	put_tile(game, "./textures/mcr3.xpm", tile * 64 - (64 
			/ 3.5), game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
	usleep(70000);
	put_tile(game, "./textures/mcr4.xpm", tile * 64 - (64 
			/ 5), game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
	usleep(70000);
	put_tile(game, "./textures/mcr1.xpm", tile * 64, game->player.y * 64);
	put_tile(game, "./textures/flr.xpm", grass * 64, game->player.y * 64);
}
