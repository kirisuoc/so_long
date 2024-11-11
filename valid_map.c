/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:50:22 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/11 10:58:09 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	check_left_and_right(char *row)
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

static void	check_top_and_bottom(char *row)
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

static void	check_walls(char **map)
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

static void	check_shape(char **map)
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

static void	check_valid_chars(char **map)
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

static void	check_minimums(char **map)	// CAMBIAR NOMBRE DE FUNCIÓN		// Luego ver si almacenamos posición en struct de cada elemento, aunque sería mejor a la hora de dibujarlo, leerlo del mapa directamente
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

void	map_is_valid(char **map)
{
	check_shape(map);
	check_walls(map);
	check_valid_chars(map);
	check_minimums(map);
}
