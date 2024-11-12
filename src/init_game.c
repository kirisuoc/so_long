/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:05:53 by erikcousill       #+#    #+#             */
/*   Updated: 2024/11/12 11:11:35 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_vars *vars, char *map_path)
{
	vars->map.path = map_path;
	vars->collected = 0;
	vars->exit_unlocked = FALSE;
	vars->map.exit_accessible = FALSE;
	vars->map.accessible_collectibles = 0;
	vars->collectibles = 0;
	vars->won = FALSE;
	vars->moves = 0;
	vars->exit_found = 0;
	vars->start_found = 0;
}
