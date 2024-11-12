/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:42:41 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/12 13:22:08 by erikcousill      ###   ########.fr       */
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
	int		px_w;
	int		px_h;
	void	*img;
}				t_sprite;

typedef struct s_player
{
	t_point		pos;
	t_point		start_pos;
	t_sprite	sprite;
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
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	t_player	player;
	t_map		map;
	t_sprite	w_sp;
	t_sprite	c_sp;
	t_sprite	s_sp;
	t_sprite	e_sp;
	t_sprite	f_sp;
	t_sprite	p_sp;
	t_sprite	yw_sp;
	BOOL		won;
	int			moves;
	int			collected;
	int			collectibles;
	BOOL		exit_unlocked;
	int			exit_found;
	int			start_found;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_vars;

#endif