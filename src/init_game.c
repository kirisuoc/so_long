/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:55:55 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/29 16:56:07 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_vars *vars, char *map_path)
{
	vars->map.path = map_path;
	vars->collected = 0;
	vars->exit_unlocked = FALSE;
	vars->map.exit_accessible = FALSE;
	vars->map.accessible_collectibles = 0;
	vars->collectibles = 0;
	vars->won = FALSE;
	vars->moves = 0;
	vars->exit_found = 0;
	vars->start_found = 0;
	vars->player.walk_frame = 0;
	vars->player.direction = 1;
}

void	init_graphics(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		map_error("Error al inicializar mlx.");
	vars->win = mlx_new_window(vars->mlx, vars->map.g_w * SIZE, \
		vars->map.g_h * SIZE, WIN_NAME);
	if (!vars->win)
		map_error("Error al crear la ventana.");
	vars->img = mlx_new_image(vars->mlx, vars->map.g_w * SIZE, \
		vars->map.g_h * SIZE);
	if (!vars->img)
		map_error("Error al crear la imagen.");
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, \
		&vars->line_length, &vars->endian);
	if (!vars->addr)
		map_error("Error al obtener la dirección de los datos de la imagen.");
}
