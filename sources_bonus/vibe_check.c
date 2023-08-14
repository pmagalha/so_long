/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vibe_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:30:06 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/01 15:14:52 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_rectangle(t_game *game)
{
	int	y;

	y = 1;
	while (y < game->rows)
	{
		if (stringlen(game->map[0]) != stringlen(game->map[y]))
			return (1);
		y++;
	}
	return (0);
}

int	check_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		while (game->map[y][x] != '\n' && y == 0)
		{
			if (game->map[y][x] != '1' || (game->map[game->rows - 1][x] != '1'))
				return (1);
			x++;
		}
		if (game->map[y][0] != '1' || game->map[y][stringlen(game->map[y])
			- 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	check_p_c(t_game *game, int x, int y)
{
	int	playercount;

	playercount = 0;
	while (game->map[y])
	{
		x = -1;
		while (game->map[y][++x] != '\n' && game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'C')
				game->collectibles++;
			if (game->map[y][x] == 'P')
			{
				playercount++;
				game->player.x = x;
				game->player.y = y;
				if (playercount > 1)
					return (1);
			}
		}
		y++;
	}
	game->collectibles = 0;
	if (playercount == 1)
		return (0);
	return (1);
}

int	check_exit(t_game *game)
{
	int	x;
	int	y;
	int	exitcount;

	y = 0;
	exitcount = 0;
	while (game->map[y])
	{
		x = -1;
		while (game->map[y][++x] != '\n' && game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'E')
			{
				exitcount++;
				game->exit.x = x;
				game->exit.y = y;
				if (exitcount > 1)
					return (1);
			}
		}
		y++;
	}
	if (exitcount == 1)
		return (0);
	return (1);
}

int	check_char(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0'
				&& game->map[y][x] != 'E' && game->map[y][x] != 'C'
				&& game->map[y][x] != 'P')
			{
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
