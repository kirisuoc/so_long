/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:54:55 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/11 12:08:34 by ecousill         ###   ########.fr       */
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


#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/libftprintf.h"
#include "libft/get_next_line.h"
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Estructura para representar las coordenadas (x, y)
typedef	struct s_pos
{
	int	x;		// Fila
	int	y;		// Columna

}			t_pos;

// Estructura para la cola en BFS
typedef	struct	s_queue;
{
	t_pos	position;
	struct	s_queue	next;
}			t_queue;

// utils.c
int		open_file(const char *filename);
char	**allocate_memory(size_t size, char *error_message);
size_t	ft_linelen(char *s);

// valid_map.c
void	map_is_valid(char **map);

// parse_map.c
void	read_and_validate_map(const char *filename, char ***map);
void	print_and_free_map(char **map);
void	map_error(char *s);



#endif
