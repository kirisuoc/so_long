/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:54:55 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/11 16:17:35 by ecousill         ###   ########.fr       */
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
# ifndef size
#	define SIZE 50
# endif
# define BOOL short int
# define TRUE 1
# define FALSE 0


# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "libft/libftprintf.h"
# include "libft/get_next_line.h"
# include "structures.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>


// utils.c
int		open_file(const char *filename);
//char	**allocate_memory(size_t size, char *error_message);
size_t	ft_linelen(char *s);
int		check_map_name(char *s);

// valid_map.c
void	map_is_valid(char **map);

// parse_map.c
	//void	read_and_validate_map(const char *filename, char ***map);
	//void	print_and_free_map(char **map);
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


#endif
