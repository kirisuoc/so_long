/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:09:51 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/29 16:59:33 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *s)
{
	ft_printf("Error\n");
	ft_printf("%s\n", s);
	exit(1);
}

void	count_grid(t_vars *vars, char c, t_point p)
{
	if (c == START)
	{
		vars->start_found++;
		vars->player.pos = p;
		vars->player.start_pos = p;
	}
	else if (c == EXIT)
		vars->exit_found++;
	else if (c == COLLECT)
		vars->collectibles++;
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
	if (c != COLLECT && c != START && c != EXIT && c != WALL && c != FLOOR)
		return (1);
	return (0);
}

void	initiate_map_filling(t_vars *vars, t_point *p)
{
	vars->map.fd = open(vars->map.path, O_RDONLY);
	vars->map.grid = malloc(vars->map.g_h * sizeof(char *));
	vars->map.tiles = malloc(vars->map.g_h * sizeof(t_tile *));
	p->px_x = 0;
	p->px_y = 0;
}
