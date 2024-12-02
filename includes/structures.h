/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:42:41 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/01 12:52:04 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "so_long.h"

typedef struct s_point
{
	size_t	px_x;
	size_t	px_y;
}				t_point;

typedef struct s_sprite
{
	int		px_w;			// Ancho del sprite
	int		px_h;			// Alto del sprite
	void	**img_seq;		// Array de sprites (para la animación)
	int		num_sprites;	// Número de sprites en la secuencia
}				t_sprite;

typedef struct s_player
{
	t_point		pos;
	t_point		start_pos;
	t_sprite	sprite;
	int			direction;
	int			walk_frame;
}				t_player;

typedef struct s_tile
{
	char	t;
	int		v;
}				t_tile;

typedef struct s_map
{
	char	*path;
	size_t	g_h;
	size_t	g_w;
	char	**grid;
	t_tile	**tiles;
	int		exit_accessible;
	int		fd;
	int		accessible_collectibles;
}				t_map;

typedef struct s_vars
{
	void		*mlx;	// Puntero a la instancia de mlx
	void		*win;	// Puntero a la ventana de mlx
	void		*img;	// Imagen en memoria para el renderizado
	char		*addr;	// Dirección de la imagen en memoria
	t_player	player;	// Jugador (con sprite animado)
	t_map		map;	// Mapa del juego
	t_sprite	w_sp;	// Sprite de muro
	t_sprite	c_sp;	// Sprite de coleccionable
	t_sprite	s_sp;	// Sprite de salida
	t_sprite	e_sp;	// Sprite de meta
	t_sprite	f_sp;	// Sprite de fondo
	t_sprite	p_sp;	// Sprite de jugador (con animación)
	t_sprite	yw_sp;	// Sprite de "You Win"
	t_sprite	en_sp;	// Sprite de enemigo (con animación)
	int			won;	// Bandera de victoria
	int			moves;	// Contador de movimientos
	int			collected;		// Contador de coleccionables
	int			collectibles;	// Total de coleccionables
	int			exit_unlocked;	// Bandera de salida desbloqueada
	int			exit_found;		// Bandera de salida encontrada
	int			start_found;	// Bandera de inicio encontrada
	int			bits_per_pixel;	// Bits por píxel (imagen)
	int			line_length;	// Longitud de la línea de la imagen
	int			endian;			// Endianess de la imagen
}				t_vars;

#endif
