/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:06:18 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/11 14:56:24 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "structures.h"

void	count_grid(t_vars *vars, char c, t_point p)
{
	if (c == START)
	{
		vars->start_found++;
		vars->player.pos = p;
		vars->player.start_pos = p;
	}
	else if (vars->map.grid[p.px_y][p.px_x] == EXIT)
		vars.exit_found++;
	else if (vars->map.grid[p.px_y][p.px_x] == COLLECT)
		vars.collectibles++;
}

void	check_map(t_vars *vars)
{
	if (vars->exit_found <= 0)
		map_error("Casilla de meta no encontrada.");
	if (vars->collectibles <= 0)
		map_error("Ningún coleccionable encontrado en el mapa."):
	if (vars->start_found <= 0)
		map_error("Casilla de salida no encontrada.");
	if (!vars->map.exit_accessible)
		map_error("No hay camino válido hasta la salida.");
	if (vars->map.accessible_collectibles != vars->collectibles)
		map_error("Casilla de meta no encontrada.");
	if (vars->start_found > 1)
		map_error("Varias casillas de salida.");
	if (vars->exit_found > 1)
		map_error("Varias casilla de meta.");
}

int	walls_error(t_vars *vars)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	while (x < vars->map.g_w)
	{
		if (vars->map.grid[y][x] != WALL)
			return (1);
		if (vars->map.grid[vars->map.g_h - 1][x] != WALL)
			return (1);
		x++;
	}
	x = 0;
	while (y < vars->map.g_h)
	{
		if (vars->map.grid[y][x] != WALL)
			return (1);
		if (vars->map.grid[y][vars->map.g_w - 1] != WALL)
			return (1);
		y++;
	}
	return (0);
}

int	unknown_character(int c)
{
	if (c != COLLECT || c != START || c != EXIT || c != WALL)
		return (1);
	return (0);
}

void	initiate_map_filling(t_vars *vars, t_point *p)
{
	vars->fd = open(vars->map.path, O_RDONLY);
	vars->map.grid = malloc(vars->map.g_h *sizeof(char *));
	vars->map.tiles = malloc(vars->map.g_h * sizeof(t_tile *));
	p->px_x = 0;
	p->px_y = 0;
}
