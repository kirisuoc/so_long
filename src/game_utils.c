/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:05:53 by erikcousill       #+#    #+#             */
/*   Updated: 2024/11/19 16:54:51 by ecousill         ###   ########.fr       */
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
	vars->needs_update = 0;

}

void	load_sprites(t_vars *vars)
{
	load_map_sprites(vars);
}

void	load_map_sprites(t_vars *vars)
{
	vars->p_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/extras/pikachu.xpm", &vars->p_sp.px_w, &vars->p_sp.px_h);
	if (!vars->p_sp.img)
		map_error("Error al cargar el sprite de Pikachu.");
	vars->f_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/pacman/floor_pm.xpm", &vars->f_sp.px_w, &vars->f_sp.px_h);
	if (!vars->f_sp.img)
		map_error("Error al cargar el sprite del suelo.");
	vars->w_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/pacman/wall_pm.xpm", &vars->w_sp.px_w, &vars->w_sp.px_h);
	if (!vars->w_sp.img)
		map_error("Error al cargar el sprite de los muros.");
	vars->s_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/s_sp.xpm", &vars->s_sp.px_w, &vars->s_sp.px_h);
	if (!vars->s_sp.img)
		map_error("Error al cargar el sprite de salida.");
	vars->e_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/extras/door-close.xpm", &vars->e_sp.px_w, &vars->e_sp.px_h);
	if (!vars->e_sp.img)
		map_error("Error al cargar el sprite de meta.");
	vars->c_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/c_sp.xpm", &vars->c_sp.px_w, &vars->c_sp.px_h);
	if (!vars->c_sp.img)
		map_error("Error al cargar el sprite de los coleccionables.");
	vars->yw_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/yw_sp.xpm", &vars->p_sp.px_w, &vars->p_sp.px_h);
	if (!vars->yw_sp.img)
		map_error("Error al cargar el sprite de You Win.");


}

void	update_player_position(t_vars *vars, t_point np)
{
	ft_printf("Total moves: %d\n", ++vars->moves);
	if (np.px_x < vars->map.g_w && np.px_y < vars->map.g_h)
	{
		if (vars->map.grid[np.px_y][np.px_x] == COLLECT)
		{
			vars->collected++;
			vars->map.grid[np.px_y][np.px_x] = FLOOR;
			if (vars->collected == vars->collectibles)
			{
				vars->exit_unlocked = TRUE;
				vars->e_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/extras/door-open.xpm", &vars->f_sp.px_w, &vars->f_sp.px_h);
			}
			vars->player.pos = np;
		}
		else if (vars->map.grid[np.px_y][np.px_x] == EXIT)
		{
			vars->player.pos = np;
			if (vars->exit_unlocked)
				vars->won = TRUE;
		}
		else if (vars->map.grid[np.px_y][np.px_x] == START)
			vars->player.pos = np;
		else if (vars->map.grid[np.px_y][np.px_x] == FLOOR)
			vars->player.pos = np;
		else if (vars->map.grid[np.px_y][np.px_x] == WALL)
			vars->player.pos = vars->player.pos;
		vars->needs_update = 1;
	}
}
