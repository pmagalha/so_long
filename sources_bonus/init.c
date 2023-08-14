/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:18:48 by pmagalha          #+#    #+#             */
/*   Updated: 2023/07/31 16:19:45 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_img(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = NULL;
	game->img.mlx_img = NULL;
	game->img.addr = NULL;
	game->img.bpp = 0;
	game->img.line_len = 0;
	game->img.endian = 0;
}

void	init_values(t_game *game)
{
	game->rows = 0;
	game->cols = 0;
	game->map = NULL;
	game->collected = 0;
	game->collectibles = 0;
	game->movements = 1;
	game->exit.x = 0;
	game->exit.y = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->valid = 0;
	game->size.x = 64;
	game->size.y = 64;
	game->enemies = 0;
	game->enemy_x = NULL;
	game->enemy_y = NULL;
	game->counter = 0;
}

t_game	*init(void)
{
	t_game	*game;

	srand(time(NULL));
	game = malloc((1) * sizeof(t_game));
	if (!game)
		return (NULL);
	init_img(game);
	init_values(game);
	return (game);
}
