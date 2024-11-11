/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:53:43 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/11 12:53:15 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "structures.h"


void	map_error(char *s)
{
	ft_printf("Error\n");
	ft_printf("%s\n", s);
	exit(1);
}

int	parse_map(t_map *map)
{
	int	fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		map_error(Mapa no encontrado.);
	map->g_h = 0;
	map->g_w = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->g_h++;
		if (map->g_h == 1)
			map->g_w = ft_linelen(line);
		if (ft_linelen(line) != map->g_w)
			map_error("El mapa no es rectangular.");
		line = get_next_line(fd);
	}
	close(fd);
	if (map->g_h == 0)
		map_error("Mapa vacio.");
	return (1);
}

int	fill_grid(t_vars *vars)
{
	t_point	g_pos;
	char	*line;

	initiate_map_filling(vars, &g_pos);
	line = get_next_line(vars->map.fd);
	while (line)
	{
		allocate_line(vars, g_pos);
		while (g_pos.px_x < vars.map.g_w)
		{
			fill_tiles(vars, line, g_pos);
			count_grid(vars, vars->map.grid[g_pos.px_y][g_pos.px_x], g_pos);
			g_pos.px_x++;
		}
		g_pos.px_x = 0;
		g_pos.px_y++;
		line = get_next_line(vars->map.fd);
	}
	close(vars->map.fd);
	if (walls_error(vars))
		map_error("El mapa no no está rodeado por muros.");


	// AQUI
	check_path(vars->player.pos, vars);
	check_map(vars);
	return (1);
}


void	fill_tiles(t_vars *vars, char *line, t_point g_pos)
{
	vars->map.grid[g_pos->px_y][g_pos->px_x] = line[g_pos.px_x];
	vars->map.tiles[g_pos->px_y][g_pos->px_x].t = line[g_pos.px_x];
	vars->map.tiles[g_pos->px_y][g_pos->px_x].v = 0;
	if (unknown_character(vars->map.tiles[g_pos.px_y][g_pos.px_x].t))
		map_error("Caracter desconocido en el mapa introducido.");
}

void	allocate_line(t_vars *vars, char *line, t_point g_pos)
{
	vars->map.grid[g_pos->px_y] = malloc((vars->map.g_w - 1) * sizeof(char));
	vars->map.tiles[g_pos->px_y] = malloc((vars->map.g_w - 1) * sizeof(t_tile));
}



static int	read_map(const char *filename, char ***map)
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
