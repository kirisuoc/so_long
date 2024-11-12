/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:30:07 by erikcousill       #+#    #+#             */
/*   Updated: 2024/11/12 11:11:41 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MAX_LINE_LENGTH 1024 // ??




/*
// Mira que hay un camino válido desde el jugador hasta la salida, pasando por todos los items. Error si no
void	check_valid_path(char **map)
{

}
*/


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
	return (0);
}

/* int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
	{
		printf("Uso: %s <archivo.ber>\n", argv[0]);
		return (1);
	}
	map = allocate_memory(sizeof(char *) * 1024, "Error al asignar memoria");
	read_and_validate_map(argv[1], &map);
	print_and_free_map(map);
	return (0);
} */
