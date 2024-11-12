/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:30:07 by erikcousill       #+#    #+#             */
/*   Updated: 2024/11/12 19:10:57 by erikcousill      ###   ########.fr       */
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

	if (load_sprite(&vars, &vars.f_sp, "img/f_sp.xpm"))
	{
		// Manejo del error si la imagen no se carga
		exit(1);
	}
	if (load_sprite(&vars, &vars.w_sp, "img/w_sp.xpm"))
	{
		// Manejo del error si la imagen no se carga
		exit(1);
	}
	if (load_sprite(&vars, &vars.p_sp, "img/extras/pikachu.xpm"))
	{
		// Manejo del error si la imagen no se carga
		exit(1);
	}
	if (load_sprite(&vars, &vars.s_sp, "img/s_sp.xpm"))
	{
		// Manejo del error si la imagen no se carga
		exit(1);
	}
	if (load_sprite(&vars, &vars.e_sp, "img/e_sp.xpm"))
	{
		// Manejo del error si la imagen no se carga
		exit(1);
	}
	if (load_sprite(&vars, &vars.c_sp, "img/c_sp.xpm"))
	{
		// Manejo del error si la imagen no se carga
		exit(1);
	}

	draw_background(&vars);
	draw_map(&vars);
	draw_player(&vars);

	display_values(&vars);
	print_variables(&vars);




	mlx_hook(vars.win, 17, 1L << 0, close_window, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_handler, &vars);

	mlx_loop(vars.mlx);
	return (0);
}


// Suponiendo que tienes una función en la que quieras mostrar los valores, por ejemplo, en un bucle principal.

void	display_values(t_vars *vars)
{
	char	str[50];

	// Muestra las coordenadas del jugador
	snprintf(str, sizeof(str), "Player position: (%zu, %zu)", vars->player.pos.px_x, vars->player.pos.px_y);
	ft_printf("Player position: (%zu, %zu)", vars->player.pos.px_x, vars->player.pos.px_y);
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0xFFFFFF, str); // Posición (10, 10) de la ventana, color blanco

	// Muestra el número de movimientos
	snprintf(str, sizeof(str), "Moves: %d", vars->moves);
	mlx_string_put(vars->mlx, vars->win, 10, 30, 0xFFFFFF, str);

	// Muestra el estado de los collectibles
	snprintf(str, sizeof(str), "Collected: %d/%d", vars->collected, vars->collectibles);
	mlx_string_put(vars->mlx, vars->win, 10, 50, 0xFFFFFF, str);

	// Muestra el estado de la exit (si está desbloqueada o no)
	snprintf(str, sizeof(str), "Exit %s", vars->exit_unlocked ? "Unlocked" : "Locked");
	mlx_string_put(vars->mlx, vars->win, 10, 100, 0xFFFFFF, str);
}

void print_variables(t_vars *vars) {

	ft_printf("\n");
    // Imprimir datos del jugador
    printf("Player position: (%zu, %zu)\n", vars->player.pos.px_x, vars->player.pos.px_y);
    printf("Start position: (%zu, %zu)\n", vars->player.start_pos.px_x, vars->player.start_pos.px_y);
    printf("Player sprite size: (%d, %d)\n", vars->player.sprite.px_w, vars->player.sprite.px_h);

    // Imprimir datos del mapa
    printf("Map path: %s\n", vars->map.path);
    printf("Map dimensions: (%zu, %zu)\n", vars->map.g_h, vars->map.g_w);
    printf("Exit accessible: %d\n", vars->map.exit_accessible);
    printf("Collectibles accessible: %d\n", vars->map.accessible_collectibles);

    // Imprimir datos de tiles
    //         printf("Tile [0][0]: %c, Value: %d\n", vars->map.tiles[0][0].t, vars->map.tiles[0][0].v);

    // Imprimir otros valores
    printf("Moves: %d\n", vars->moves);
    printf("Collected: %d\n", vars->collected);
    printf("Total collectibles: %d\n", vars->collectibles);
    printf("Exit unlocked: %d\n", vars->exit_unlocked);
    printf("Exit found: %d\n", vars->exit_found);
    printf("Start found: %d\n", vars->start_found);
    printf("Bits per pixel: %d\n", vars->bits_per_pixel);
    printf("Line length: %d\n", vars->line_length);
    printf("Endian: %d\n", vars->endian);
    printf("Won: %d\n", vars->won);
}


void	handle_sigtstp(int sig)
{
	(void)sig; // Para que no se genere un warning sobre el parámetro no usado
	ft_printf("Programa detenido con CTRL+Z. Cerrando ventana...\n");
	// Aquí puedes hacer una limpieza si es necesario antes de finalizar
	exit(0); // Salir del programa correctamente
}
