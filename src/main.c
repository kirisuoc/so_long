/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:30:07 by erikcousill       #+#    #+#             */
/*   Updated: 2024/11/12 13:23:10 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param);

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 1)
		map_error("No se especificó ningún mapa.");
	else if (ac > 2)
		map_error("Demasiados argumentos.");
	else if (ac == 2 && check_map_name(av[1]))
		map_error("Extensión de archivo del mapa incorrecta.");
	init_game(&vars, av[1]);
	parse_map(&vars.map);
	fill_grid(&vars);
	free_tiles(&vars);

	// Juego
 	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map.g_w * SIZE, vars.map.g_h * SIZE, WIN_NAME);


	mlx_hook(vars.win, 17, 0, close_window, NULL); // Cambiar NULL por &vars ??
	mlx_loop(vars.mlx);
	return (0);
}


int	close_window(void *param)
{
	(void)param;
	exit(0);
}
