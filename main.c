/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:30:07 by erikcousill       #+#    #+#             */
/*   Updated: 2024/11/07 19:42:37 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

int	read_map(const char *filename, char ***map)
{
	int		fd;
	int		bytes_read;
	int		line;
	char	buffer[MAX_LINE_LENGTH];

	// Abrir el archivo .ber
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}

	line = 0;
	// Leer el archivo linea por linea
	while ((bytes_read = read(fd, buffer, MAX_LINE_LENGTH)) > 0)
	{
		buffer[bytes_read] = '\0';

		// Asignar memoria para cada linea y copiarla
		(*map)[line] = strdup(buffer);
		if (!map[line])
		{
			perror("Error al asignar memoria");
			close(fd);
			exit(EXIT_FAILURE);
		}
		line++;
	}
	close(fd);
	return (0);
}

// Terminar chequeando primera fila, última fila, primera columa y última columna
void	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (i == 0)
			{
				if (map[i][j] != 1)
				{
					perror("Hay algún muro exterior incorrecto");
					exit (EXIT_FAILURE);
				}
			}
			j++;
		}
		i++;
	}
}

// Chequear que es rectangular --> Todas las filas tienen el mismo tamaño y lo mismo para las columnas
void	check_shape(char **map)
{

}

// Mira que hay un camino válido desde el jugador hasta la salida, pasando por todos los items. Error si no
void	check_valid_path(char **map)
{

}
// Mira que solo hay un protagonista y (guarda dónde??). Error si no
void	start_position(char **map)
{

}
// Mira cuántos coleccionables hay y (guarda dónde están??). Error si no hay al menos 1 ?? En principio no.
void	check_items(char **map)
{

}

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	if (argc != 2)
	{
		printf("Uso: %s <archivo.ber>\n", argv[0]);
		return (1);
	}
	map = malloc(sizeof(char *) * 1024);
	if (read_map(argv[1], &map) == -1)
	{
		perror("Error al leer el mapa");
		return (2);
	}
	check_walls(map);
		return (1);
	i = 0;
	while (map[i] != NULL)
	{
		printf("%s", map[i]);
		free(map[i]);	// Liberar cada línea después de imprimirla
		i++;
	}
	free(map);
	return (0);
}
