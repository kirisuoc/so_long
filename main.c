/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:30:07 by erikcousill       #+#    #+#             */
/*   Updated: 2024/11/08 18:28:30 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/libftprintf.h"
#include "libft/get_next_line.h"
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

		int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

		char	**allocate_memory(size_t size, char *error_message)
{
	char	**ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror(error_message);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

int		read_map(const char *filename, char ***map)
{
	int		fd;
	int		line;
	char	*line_content;

	// Abrir el archivo .ber
	fd = open_file(filename);

	// Reserva espacio para el mapa
	*map = allocate_memory(1024 * sizeof(char *), "Error al asignar memoria para el mapa (2)");

	line = 0;
	// Leer cada línea del archivo usando get_next_line
	while ((line_content = get_next_line(fd)) != NULL)
	{
		if (line_content[0] != '\0')
		{
			(*map)[line] = ft_strdup(line_content);
			if (!(*map)[line])
			{
				perror("Error al copiar la línea");
				return (-1);
			}
			line++;
		}
		else
			free(line_content);
	}

	(*map)[line] = NULL;
	close(fd);
	return (0);
}




		void	check_left_and_right(char *row)
{
	int	row_length;

	row_length = ft_strlen(row);
	if (row[row_length - 1] == '\n')
	{
		row[row_length - 1] = '\0';
		row_length--;
	}
	if (row[0] != '1' || row[row_length - 1] != '1')
	{
		ft_printf("Hay un muro lateral incorrecto.\n");
		exit(EXIT_FAILURE);
	}
}

		void	check_top_and_bottom(char *row)
{
	int	i;

	i = 0;
	while (row[i] != '\0')
	{
		if (row[i] != '1')
		{
			ft_printf("El techo o el suelo son incorrectos.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_walls(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		check_left_and_right(map[i]);
		if (i == 0 || map[i + 1] == NULL)
			check_top_and_bottom(map[i]);
		i++;
	}
}

// Chequear que es rectangular --> Todas las filas tienen el mismo tamaño
void	check_shape(char **map)
{
	int	i;
	size_t	row_length;
	size_t	current_length;

	// Obtener la longitud de la primera fila
	row_length = ft_strlen(map[0]);

	// Verificar que todas las filas tengan la misma longitud
	i = 1;
	while (map[i] != NULL)
	{
		current_length = ft_strlen(map[i]);
		if (current_length != row_length)
		{
			ft_printf("El mapa no es rectangular.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_valid_chars(char **map)
{
	int	i;
	int	j;
	char	valid_chars[] = "01CEP";

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!ft_strchr(valid_chars, map[i][j]))
			{
				ft_printf("Error: carácter no válido '%c' en el mapa.\n", map[i][j]);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_minimums(char **map)	// CAMBIAR NOMBRE DE FUNCIÓN		// Luego ver si almacenamos posición en struct de cada elemento, aunque sería mejor a la hora de dibujarlo, leerlo del mapa directamente
{
	int	starting_pos;
	int	collectibles;
	int	finish_line;
	int		i;
	int		j;

	i = 0;
	starting_pos = 0;
	collectibles = 0;
	finish_line = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr("P", map[i][j]))
				starting_pos++;
			if (ft_strchr("C", map[i][j]))
				collectibles++;
			if (ft_strchr("E", map[i][j]))
				finish_line++;
			j++;
		}
		i++;
	}
	if (starting_pos != 1 || finish_line != 1 || collectibles < 1 )
	{
		ft_printf("El mapa debe tener solamente una salida, al menos \
un objeto y solamente una posición inicial.\n");
		exit(EXIT_FAILURE);
	}
}
/*
// Mira que hay un camino válido desde el jugador hasta la salida, pasando por todos los items. Error si no
void	check_valid_path(char **map)
{

}
*/

void	map_is_valid(char **map)
{
	check_shape(map);
	check_walls(map);
	check_valid_chars(map);
	check_minimums(map);
}


void	read_and_validate_map(const char *filename, char ***map)
{
	*map = allocate_memory(1024 * sizeof(char *),
		"Error al asignar memoria para el mapa (1)");

	// Leer el archivo y almacenar cada linea en el mapa
	if (read_map(filename, map) == -1)
	{
		perror ("Error al leer el mapa");
		exit(EXIT_FAILURE);
	}

	map_is_valid(*map); // Llama a check_shape(), check_walls()
}

void	print_and_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		free(map[i]);	// Liberar cada línea después de imprimirla
		i++;
	}
	free(map); // Liberar el arreglo de punteros
}

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
