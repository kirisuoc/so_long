/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:46:17 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/02 15:17:38 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_map_sprites(t_vars *vars);

void	load_sprites(t_vars *vars)
{
	load_map_sprites(vars);
	load_player_sprites(vars);
	load_exit_sprites(vars);
	load_counter_sprites(vars);
	load_coin_sprites(vars);
	load_enemy_sprites(vars);
}

void	load_sprite(t_vars *vars, t_sprite *sprite, int num_sprites, \
		char *file_paths[])
{
	int	i;

	sprite->img_seq = malloc(sizeof(void *) * num_sprites);
	if (!sprite->img_seq)
		map_error("Error al asignar memoria para las secuencias de imágenes.");
	i = 0;
	while (i < num_sprites)
	{
		sprite->img_seq[i] = mlx_xpm_file_to_image(vars->mlx, file_paths[i], \
			&sprite->px_w, &sprite->px_h);
		if (!sprite->img_seq[i])
			map_error("Error al cargar una de las imágenes de sprite.");
		i++;
	}
	sprite->num_sprites = num_sprites;
}

static void	load_map_sprites(t_vars *vars)
{
	char	*floor_paths[1];
	char	*wall_paths[1];
	char	*start_paths[1];
	char	*yw_paths[1];
	char	*gameover_paths[1];

	floor_paths[0] = "img/xpm/floor.xpm";
	wall_paths[0] = "img/xpm/wall.xpm";
	start_paths[0] = "img/xpm/start.xpm";
	yw_paths[0] = "img/xpm/yw_sp.xpm";
	gameover_paths[0] = "img/xpm/gameover_sp.xpm";
	load_sprite(vars, &vars->f_sp, 1, floor_paths);
	load_sprite(vars, &vars->w_sp, 1, wall_paths);
	load_sprite(vars, &vars->s_sp, 1, start_paths);
	load_sprite(vars, &vars->yw_sp, 1, yw_paths);
	load_sprite(vars, &vars->gameover_sp, 1, gameover_paths);
}
