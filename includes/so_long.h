/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:54:55 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/13 13:36:52 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_W 500
# define WIN_H 500
# define WIN_NAME "so_long"
# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'
# ifndef SIZE
#  define SIZE 50
# endif
# define BOOL short int
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

// main.c
int	render(t_vars *vars);

// utils.c
int		close_window(t_vars *vars);
int 	key_handler(int keycode, t_vars *vars);
size_t	ft_linelen(char *s);
int		check_map_name(char *s);

// valid_map.c
void	map_is_valid(char **map);

// parse_map.c
void	map_error(char *s);
int		parse_map(t_map *map);
int		fill_grid(t_vars *vars);
void	fill_tiles(t_vars *vars, char *line, t_point g_pos);
void	allocate_line(t_vars *vars, t_point g_pos);

// map_parser_utils.c
void	count_grid(t_vars *vars, char c, t_point p);
void	check_map(t_vars *vars);
int		walls_error(t_vars *vars);
int		unknown_character(int c);
void	initiate_map_filling(t_vars *vars, t_point *p);

// path_checker.c
void	check_path(t_point p, t_vars *vars);

// free_tiles.c
void	free_tiles(t_vars *vars);
void	free_map(t_vars *vars);

// game_utils.c
void	init_game(t_vars *vars, char *map_path);
int		load_sprite(t_vars *vars, t_sprite *sprite, char *file_path);
void	update_player_position(t_vars *vars, t_point np);

// draw_background.c
void	draw_background(t_vars *vars);
void	draw_map(t_vars *vars);
void	draw_player(t_vars *vars);
void	put_sp(t_vars *vars, t_point s, char t);
void	load_map_sprites(t_vars *vars);
void	load_sprites(t_vars *vars);


#endif
