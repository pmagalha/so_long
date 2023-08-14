/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:11:07 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/01 15:13:52 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(t_game *game, char *imgpath, int x, int y)
{
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
		game->img.mlx_img = 0;
	}
	game->img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, imgpath,
			&game->size.x, &game->size.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, x,
		y);
}

void	render_win(t_game *game)
{
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->cols * 64, game->rows
			* 64, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		return ;
	}
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, game->cols * 64, game->rows
			* 64);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
}

void	render_map(t_game *game, int x, int y)
{
	if (y == 0 && x == 0)
		put_tile(game, "./textures/ltcorner.xpm", x * 64, y * 64);
	else if (y == 0 && x < (game->cols - 1))
		put_tile(game, "./textures/wall_top.xpm", x * 64, y * 64);
	else if (y == 0 && x == (game->cols - 1))
		put_tile(game, "./textures/rtcorner.xpm", x * 64, y * 64);
	else if (x == 0 && y < (game->rows - 1))
		put_tile(game, "./textures/wall_left.xpm", x * 64, y * 64);
	else if (x == (game->cols - 1) && y < (game->rows - 1))
		put_tile(game, "./textures/wall_right.xpm", x * 64, y * 64);
	else if (y == (game->rows - 1) && x == 0)
		put_tile(game, "./textures/lbcorner.xpm", x * 64, y * 64);
	else if (y == (game->rows - 1) && x < (game->cols - 1))
		put_tile(game, "./textures/wall_bottom.xpm", x * 64, y * 64);
	else if (y == (game->rows - 1) && x == (game->cols - 1))
		put_tile(game, "./textures/rbcorner.xpm", x * 64, y * 64);
}

void	render_pce(t_game *game, int x, int y, char c)
{
	if (c == 'P')
		put_tile(game, "./textures/mcd1.xpm", x * 64, y * 64);
	if (c == 'C')
		put_tile(game, "./textures/collectibles.xpm", x * 64, y * 64);
	if (c == '0')
		put_tile(game, "./textures/flr.xpm", x * 64, y * 64);
	if (c == '1')
		put_tile(game, "./textures/obstacles.xpm", x * 64, y * 64);
	if (c == 'E')
		put_tile(game, "./textures/exitopen1.xpm", x * 64, y * 64);
}

void	render(t_game *game)
{
	int	x;
	int	y;

	render_win(game);
	if (!game->win_ptr)
		return ;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x] != '\0')
		{
			render_pce(game, x, y, game->map[y][x]);
			render_map(game, x, y);
		}
	}
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, &free_all,
		game);
	mlx_loop(game->mlx_ptr);
}
