/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:30:07 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/02 13:39:20 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render(t_vars *vars);

int	main(int ac, char **av)
{
	t_vars	vars;

	ft_bzero(&vars, sizeof(t_vars));
	if (ac == 1)
		map_error("No se especificó ningún mapa.");
	else if (ac > 2)
		map_error("Demasiados argumentos.");
	else if (ac == 2 && check_map_name(av[1]))
		map_error("Extensión de archivo del mapa incorrecta.");
	init_game(&vars, av[1]);
	parse_map(&vars.map);
	fill_grid(&vars);
	validate_map(&vars);
	free_tiles(&vars);
	init_graphics(&vars);
	load_sprites(&vars);
	mlx_hook(vars.win, 17, 1L << 0, close_window, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_handler, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

static int	render(t_vars *vars)
{
	draw_background(vars);
	draw_map(vars);
	draw_player(vars);
	draw_counter(vars);
	if (vars->game_over)
		draw_gameover(vars);
	else if (vars->won)
		draw_victory(vars);
	update_coin_frames(vars);
	update_enemy_frames(vars);
	vars->tick++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
