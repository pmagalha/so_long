/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:15:45 by pmagalha          #+#    #+#             */
/*   Updated: 2023/08/01 17:49:30 by pmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define MLX_ERROR 1

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <time.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_game
{
	char	**map;
	int		rows;
	int		cols;
	int		collectibles;
	int		collected;
	int		valid;
	int		movements;
	int		enemies;
	int		*enemy_x;
	int		*enemy_y;
	int		counter;
	void	*mlx_ptr;
	void	*win_ptr;
	t_point	size;
	t_point	player;
	t_point	exit;
	t_img	img;
}			t_game;

/*Init functions*/
t_game		*init(void);
int			init_enemy(t_game *game);

/*Vibe check functions*/
int			stringlen(char *str);
int			check_walls(t_game *game);
int			is_rectangle(t_game *game);
int			check_p_c(t_game *game, int x, int y);
int			check_exit(t_game *game);
int			check_char(t_game *game);
int			path_check(char *file, t_game *game, int x, int y);
int			free_all(t_game *game);
int			handle_keypress(int keysym, t_game *game);
void		flood_fill(char **map_cpy, t_game *game, int x, int y);
void		freemap(char **map);
void		render(t_game *game);
void		render_win(t_game *game);
void		put_tile(t_game *game, char *imgpath, int x, int y);
char		**createmap(char *file, t_game *game);

/*Movement functions*/
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);

void		w_conditions(t_game *game);
void		a_conditions(t_game *game);
void		d_conditions(t_game *game);
void		s_conditions(t_game *game);

void		move_up_aux(t_game *game, int tile, int grass);
void		move_down_aux(t_game *game, int grass, int tile);
void		move_left_aux(t_game *game, int grass, int tile);
void		move_right_aux(t_game *game, int grass, int tile);

void		win_condition(t_game *game);

/*Animation functions*/
int			exit_animation(t_game *game);
int			anim_loops(t_game *game);
void		eat_animation(t_game *game);
void		colleting(t_game *game);
void		kill_player(t_game *game);
void		kill_player2(t_game *game);
void		render_moves_counter(t_game *game);
void		exit_open(t_game *game);
void		exit_anim(t_game *game);

/*Enemies functions*/

int			moveability(t_game *game, int x, int y);
void		move_enemy(t_game *game, int enemies);
void		render_enemy(t_game *game);
void		enemy_up(t_game *game, int enemies);
void		enemy_down(t_game *game, int enemies);
void		enemy_right(t_game *game, int enemies);
void		enemy_left(t_game *game, int enemies);
void		enemy_move_up(t_game *game, int enemies, int *x, int *y);
void		enemy_move_down(t_game *game, int enemies, int *x, int *y);
void		enemy_move_left(t_game *game, int enemies, int *x, int *y);
void		enemy_move_right(t_game *game, int enemies, int *x, int *y);
void		enemy_pos(t_game *game, int moves);

#endif