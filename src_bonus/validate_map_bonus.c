/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:34:50 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/02 13:46:39 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map(t_vars *vars);

void	validate_map(t_vars *vars)
{
	if (walls_error(vars))
	{
		free_map(vars);
		map_error("El mapa no está rodeado por muros.");
	}
	check_path(vars->player.pos, vars);
	check_map(vars);
}

static void	check_map(t_vars *vars)
{
	char	*error_message;

	error_message = "";
	if (vars->exit_found <= 0)
		error_message = "Casilla de meta no encontrada.";
	else if (vars->collectibles <= 0)
		error_message = "Ningún coleccionable encontrado en el mapa.";
	else if (vars->start_found <= 0)
		error_message = "Casilla de salida no encontrada.";
	else if (!vars->map.exit_accessible)
		error_message = "No hay camino válido hasta la salida.";
	else if (vars->map.accessible_collectibles != vars->collectibles)
		error_message = "Casilla de meta no encontrada.";
	else if (vars->start_found > 1)
		error_message = "Varias casillas de salida.";
	else if (vars->exit_found > 1)
		error_message = "Varias casilla de meta.";
	if (ft_strlen(error_message) > 1)
	{
		free_tiles(vars);
		free_map(vars);
		map_error(error_message);
	}
}
