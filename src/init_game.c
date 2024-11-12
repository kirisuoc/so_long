/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:05:53 by erikcousill       #+#    #+#             */
/*   Updated: 2024/11/12 17:39:56 by erikcousill      ###   ########.fr       */
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
}

int	load_sprite(t_vars *vars, t_sprite *sprite, char *file_path)
{
	sprite->img = mlx_xpm_file_to_image(vars->mlx, file_path, &sprite->px_w, &sprite->px_h);
	if (!sprite->img)
	{
		ft_printf("Hola");
		// Error al cargar la imagen
		return (1);
	}
	return (0);
}
