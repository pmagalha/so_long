/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:15:11 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/01 13:49:50 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	linecount(char *file, t_game *game)
{
	int		fd;
	int		linecount;
	char	*gnl;

	linecount = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		linecount++;
		free(gnl);
		gnl = get_next_line(fd);
	}
	close(fd);
	free(gnl);
	game->rows = linecount;
}

int	vibe_check(char *file, t_game *game)
{
	int	vibecheck;

	vibecheck = check_walls(game) + is_rectangle(game) + check_p_c(game, 0, 0)
		+ check_exit(game) + check_char(game);
	if (vibecheck == 0)
		vibecheck += path_check(file, game, 0, 0);
	if (vibecheck != 0)
	{
		ft_printf("Error\nInvalid Map\n");
		game->valid++;
	}
	return (vibecheck);
}

int	file_check(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!ft_strrchr(file, '.') || (fd < 0))
	{
		ft_printf("Error\nInvalid file\n");
		return (1);
	}
	if (ft_strncmp(ft_strrchr(file, '.'), ".ber", 4))
	{
		ft_printf("Error\nInvalid file\n");
		return (1);
	}
	close(fd);
	return (0);
}

char	**createmap(char *file, t_game *game)
{
	int		i;
	int		fd;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	linecount(file, game);
	map = malloc((game->rows + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (i < game->rows)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			freemap(map);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	int		i;
	int		is_map_valid;

	i = 0;
	if (argc != 2 || file_check(argv[1]))
		return (1);
	game = init();
	game->map = createmap(argv[1], game);
	game->cols = stringlen(game->map[0]);
	is_map_valid = vibe_check(argv[1], game);
	if (game->valid != 0 || !game->map)
	{
		free_all(game);
		return (1);
	}
	if (init_enemy(game))
	{
		free_all(game);
		return (1);
	}
	render(game);
	freemap(game->map);
	free(game);
}
