/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_animations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:38:42 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/01 15:14:28 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	anim_loops(t_game *game)
{
	if (game->collected == game->collectibles)
	{
		put_tile(game, "./textures/exitopen1.xpm", game->exit.x * 64,
			game->exit.y * 64);
		usleep(80000);
		put_tile(game, "./textures/exitopen2.xpm", game->exit.x * 64,
			game->exit.y * 64);
		usleep(80000);
	}
	put_tile(game, "./textures/idle2.xpm", game->player.x * 64, game->player.y
		* 64);
	usleep(80000);
	put_tile(game, "./textures/idle3.xpm", game->player.x * 64, game->player.y
		* 64);
	usleep(80000);
	put_tile(game, "./textures/idle4.xpm", game->player.x * 64, game->player.y
		* 64);
	usleep(80000);
	put_tile(game, "./textures/idle3.xpm", game->player.x * 64, game->player.y
		* 64);
	usleep(80000);
	return (0);
}

void	eat_animation(t_game *game)
{
	put_tile(game, "./textures/eating1.xpm", game->player.x * 64,
		game->player.y * 64);
	put_tile(game, "./textures/eating2.xpm", game->player.x * 64,
		game->player.y * 64);
	usleep(120000);
	put_tile(game, "./textures/eating3.xpm", game->player.x * 64,
		game->player.y * 64);
	usleep(120000);
	put_tile(game, "./textures/eating4.xpm", game->player.x * 64,
		game->player.y * 64);
	usleep(120000);
	put_tile(game, "./textures/mcd1.xpm", game->player.x * 64,
		game->player.y * 64);
	usleep(70000);
}

void	kill_player(t_game *game)
{
	put_tile(game, "./textures/death1.xpm", game->player.x * 64,
		game->player.y * 64);
	usleep(100000);
	put_tile(game, "./textures/death2.xpm", game->player.x * 64,
		game->player.y * 64);
	usleep(1200000);
	put_tile(game, "./textures/death3.xpm", game->player.x * 64,
		game->player.y * 64);
	usleep(100000);
	put_tile(game, "./textures/death4.xpm", game->player.x * 64,
		game->player.y * 64);
	usleep(100000);
	put_tile(game, "./textures/death5.xpm", game->player.x * 64,
		game->player.y * 64);
	usleep(100000);
	kill_player2(game);
}

void	kill_player2(t_game *game)
{
	put_tile(game, "./textures/death6.xpm", game->player.x * 64,
		game->player.y * 64);
	usleep(100000);
	put_tile(game, "./textures/death7.xpm", game->player.x * 64,
		game->player.y * 64);
	usleep(100000);
	put_tile(game, "./textures/death7.xpm", game->player.x * 64,
		game->player.y * 64);
	usleep(100000);
	put_tile(game, "./textures/flr.xpm", game->player.x * 64,
		game->player.y * 64);
	usleep(100000);
	ft_printf("\033[1;31m= YOU DIED =\033[0m\n");
	free_all(game);
}

void	render_moves_counter(t_game *game)
{
	char	*moves;
	int		x;
	int		y;

	x = 1 / 1.7;
	y = game->rows;
	put_tile(game, "./textures/black.xpm", x * 64, y * 64);
	put_tile(game, "./textures/black.xpm", (x + 1) * 64, y * 64);
	moves = ft_itoa(game->movements);
	x = 64 / 1.7;
	y = (game->rows) * 64 + 25;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, x + 42, y, 0x0000FF00, moves);
	free (moves);
}
