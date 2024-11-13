/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:09:21 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/13 12:06:47 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tiles(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < vars->map.g_h)
	{
		free(vars->map.tiles[i]);
		vars->map.tiles[i] = NULL;
		i++;
	}
	free(vars->map.tiles);
	vars->map.tiles = NULL;
}

/* void free_map(t_vars *vars)
{
    // Liberar las filas de grid y tiles
    for (size_t i = 0; i < vars->map.g_h; i++)
    {
        free(vars->map.grid[i]);  // Liberar cada fila de grid
        free(vars->map.tiles[i]); // Liberar cada fila de tiles
    }

    // Liberar las matrices principales (grid y tiles)
    free(vars->map.grid);
    free(vars->map.tiles);

    // Si tienes otros recursos dinámicos (por ejemplo, sprites, imágenes, etc.), libéralos también
    free(vars->map.path); // Si path es una cadena dinámica
}
 */
