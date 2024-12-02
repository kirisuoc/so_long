/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:54:55 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/02 16:23:02 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_W 500
# define WIN_H 500
# define WIN_NAME "Catch The Coin"
# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'
# define ENEMY 'X'
# ifndef SIZE
#  define SIZE 50
# endif
# define TRUE 1
# define FALSE 0
# include "mlx.h"
# include "libftprintf.h"
# include "get_next_line.h"
# include "structures.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

// game_utils.c
void	move_player(t_vars *vars, int new_x, int new_y, int direction);

void	update_coin_frames(t_vars *vars);
void	update_enemy_frames(t_vars *vars);

// init_game.c
void	init_game(t_vars *vars, char *map_path);
void	init_graphics(t_vars *vars);

// map_parser.c
void	parse_map(t_map *map);
void	fill_grid(t_vars *vars);

// map_parser_utils.c
void	map_error(char *s);
void	count_grid(t_vars *vars, char c, t_point p);
int		walls_error(t_vars *vars);
int		unknown_character(int c);
void	initiate_map_filling(t_vars *vars, t_point *p);

// free.c
void	free_tiles(t_vars *vars);
void	free_map(t_vars *vars);
void	free_graphics(t_vars *vars);
void	free_sprites(t_vars *vars);

// validate_map.c
void	validate_map(t_vars *vars);

// path_checker.c
void	check_path(t_point p, t_vars *vars);

// utils.c
int		close_window(t_vars *vars);
size_t	ft_linelen(char *s);
int		check_map_name(char *s);

// sprites_load.c
void	load_sprites(t_vars *vars);
void	load_sprite(t_vars *vars, t_sprite *sprite, int num_sprites, \
		char *file_paths[]);

// sprites_load_animated.c
void	load_player_sprites(t_vars *vars);
void	load_exit_sprites(t_vars *vars);
void	load_counter_sprites(t_vars *vars);
void	load_coin_sprites(t_vars *vars);
void	load_enemy_sprites(t_vars *vars);

// draw.c
void	draw_background(t_vars *vars);
void	draw_map(t_vars *vars);

// draw_animated.c
void	draw_player(t_vars *vars);
void	draw_counter(t_vars *vars);
void	draw_victory(t_vars *vars);
void	draw_gameover(t_vars *vars);

// draw_utils.c
void	draw_sprt_to_mem(t_vars *vars, void *sprite_img, int x_offset, \
		int y_offset);
// update_frames.c
void	update_coin_frames(t_vars *vars);
void	update_enemy_frames(t_vars *vars);

// keys.c
int		key_handler(int keycode, t_vars *vars);

#endif
