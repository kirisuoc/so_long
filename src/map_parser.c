/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:53:43 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/12 13:22:45 by erikcousill      ###   ########.fr       */
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
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		map_error("Mapa no encontrado.");
	map->g_h = 0;
	map->g_w = 0;
	line = get_next_line(fd);
	while (line && ft_linelen(line) != 0)
	{
		map->g_h++;
		if (map->g_h == 1)
			map->g_w = ft_linelen(line);
		if (ft_linelen(line) != map->g_w)
			map_error("El mapa no es rectangular.");
		//free(line);
		line = get_next_line(fd);
	}
	//free(line);
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
	while (line && ft_linelen(line) != 0)
	{
		allocate_line(vars, g_pos);
		while (g_pos.px_x < vars->map.g_w)
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
		map_error("El mapa no está rodeado por muros.");
	check_path(vars->player.pos, vars);
	check_map(vars);
	return (1);
}

void	fill_tiles(t_vars *vars, char *line, t_point g_pos)
{
	vars->map.grid[g_pos.px_y][g_pos.px_x] = line[g_pos.px_x];
	vars->map.tiles[g_pos.px_y][g_pos.px_x].t = line[g_pos.px_x];
	vars->map.tiles[g_pos.px_y][g_pos.px_x].v = 0;
	if (unknown_character(vars->map.tiles[g_pos.px_y][g_pos.px_x].t))
		map_error("Caracter desconocido en el mapa introducido.");
}

void	allocate_line(t_vars *vars, t_point g_pos)
{
	vars->map.grid[g_pos.px_y] = malloc((vars->map.g_w - 1) * sizeof(char));
	vars->map.tiles[g_pos.px_y] = malloc((vars->map.g_w - 1) * sizeof(t_tile));
}
