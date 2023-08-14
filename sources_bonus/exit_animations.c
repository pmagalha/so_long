/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:58:42 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/03 14:21:05 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_open(t_game *game)
{
	put_tile(game, "./textures/exitopening1.xpm", game->exit.x * 64,
		game->exit.y * 64);
	usleep(80000);
	put_tile(game, "./textures/exitopening2.xpm", game->exit.x * 64,
		game->exit.y * 64);
	usleep(80000);
	put_tile(game, "./textures/exitopening3.xpm", game->exit.x * 64,
		game->exit.y * 64);
	usleep(80000);
	put_tile(game, "./textures/exitopening4.xpm", game->exit.x * 64,
		game->exit.y * 64);
	usleep(80000);
	put_tile(game, "./textures/exitopening4.xpm", game->exit.x * 64,
		game->exit.y * 64);
	usleep(120000);
}

void	exit_anim(t_game *game)
{
	put_tile(game, "./textures/exiting1.xpm", game->exit.x * 64, game->exit.y
		* 64);
	put_tile(game, "./textures/exiting2.xpm", game->exit.x * 64, game->exit.y
		* 64);
	usleep(500000);
	put_tile(game, "./textures/exiting3.xpm", game->exit.x * 64, game->exit.y
		* 64);
	usleep(80000);
	put_tile(game, "./textures/exiting4.xpm", game->exit.x * 64, game->exit.y
		* 64);
	usleep(80000);
	put_tile(game, "./textures/exiting5.xpm", game->exit.x * 64, game->exit.y
		* 64);
	usleep(80000);
	put_tile(game, "./textures/exiting6.xpm", game->exit.x * 64, game->exit.y
		* 64);
	usleep(80000);
	put_tile(game, "./textures/exiting7.xpm", game->exit.x * 64, game->exit.y
		* 64);
	usleep(80000);
	ft_printf("\033[0;32m= YOU WIN =\033[0m\n");
	free_all(game);
}
