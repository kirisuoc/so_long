/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:09:21 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/11 15:11:20 by ecousill         ###   ########.fr       */
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
