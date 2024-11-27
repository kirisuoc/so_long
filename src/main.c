/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:30:07 by erikcousill       #+#    #+#             */
/*   Updated: 2024/11/27 13:55:20 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_values(t_vars *vars);
void	print_variables(t_vars *vars);
void	handle_sigtstp(int sig);

int	main(int ac, char **av)
{
	t_vars	vars;

	// Configurar la señal SIGTSTP para manejar CTRL+Z
	signal(SIGTSTP, handle_sigtstp);

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

	// Inicializar la imagen en memoria con el tamaño de la ventana
	vars.img = mlx_new_image(vars.mlx, vars.map.g_w * SIZE, vars.map.g_h * SIZE);

	// Obtener la dirección de los datos de la imagen en memoria
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);

	load_sprites(&vars);
	draw_background(&vars);
	draw_map(&vars);
	draw_player(&vars);




	mlx_hook(vars.win, 17, 1L << 0, close_window, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_handler, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);

	mlx_loop(vars.mlx);
	//mlx_destroy_image(vars.mlx, vars.img);
	//mlx_destroy_window(vars.mlx, vars.win);

	//free_map(&vars); ??
	return (0);
}

int	render(t_vars *vars)
{
/* 	if (vars->needs_update)
	{ */
		draw_background(vars);
		if (!vars->won)
		{
			draw_map(vars);
			draw_player(vars);
			// draw_moves(vars);
		}
	 	else
		{
			draw_map(vars);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->yw_sp.img, (vars->map.g_w * SIZE - 150) / 2, (vars->map.g_h * SIZE - 150) / 2);
		}
//		vars->needs_update = 0;
//	}

	return (0);
}
// Suponiendo que tienes una función en la que quieras mostrar los valores, por ejemplo, en un bucle principal.


void	handle_sigtstp(int sig)
{
	(void)sig; // Para que no se genere un warning sobre el parámetro no usado
	ft_printf("Programa detenido con CTRL+Z. Cerrando ventana...\n");
	// Aquí puedes hacer una limpieza si es necesario antes de finalizar
	exit(0); // Salir del programa correctamente
}
