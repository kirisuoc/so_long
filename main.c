/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:30:07 by erikcousill       #+#    #+#             */
/*   Updated: 2024/11/11 11:00:24 by ecousill         ###   ########.fr       */
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


int	main(int argc, char **argv)
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
}
