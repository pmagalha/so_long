/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:22:22 by pmagalha          #+#    #+#             */
/*   Updated: 2023/07/10 16:30:22 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	stringlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	flood_fill(char **map_cpy, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->rows || x >= game->cols)
		return ;
	if (map_cpy[y][x] == 'F' || map_cpy[y][x] == '1')
		return ;
	if (map_cpy[y][x] == 'C')
	{
		map_cpy[y][x] = 'F';
		game->collectibles++;
	}
	else
		map_cpy[y][x] = 'F';
	flood_fill(map_cpy, game, x - 1, y);
	flood_fill(map_cpy, game, x + 1, y);
	flood_fill(map_cpy, game, x, y + 1);
	flood_fill(map_cpy, game, x, y - 1);
}

int	path_check(char *file, t_game *game, int x, int y)
{
	char	**map_cpy;

	map_cpy = createmap(file, game);
	if (!map_cpy)
		return (1);
	flood_fill(map_cpy, game, game->player.x, game->player.y);
	while (map_cpy[y])
	{
		while (map_cpy[y][x] != '\n' && map_cpy[y][x] != '\0')
		{
			if (map_cpy[y][x] == 'C' || map_cpy[y][x] == 'E')
			{
				freemap(map_cpy);
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	freemap(map_cpy);
	return (0);
}
