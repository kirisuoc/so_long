/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:06:18 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/11 12:44:20 by ecousill         ###   ########.fr       */
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

void	initiate_map_filling(t_vars *vars, t_point *p)
{
	vars->fd = open(vars->map.path, O_RDONLY);
	vars->map.grid = malloc(vars->map.g_h *sizeof(char *));
	vars->map.tiles = malloc(vars->map.g_h * sizeof(t_tile *));
	p->px_x = 0;
	p->px_y = 0;
}
