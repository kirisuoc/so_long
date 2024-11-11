/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:51:49 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/11 14:41:44 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "structures.h"

void	check_path(t_point p, t_vars *vars)
{
	size_t	g_w;
	size_t	g_h;

	g_w = vars->map.g_w;
	g_h = vars->map.g_h;
	if (vars->map.grid[p.px_y][p.px_x] == WALL) || vars->map.tiles[p.px_y][p.px_x].v == 1 || p.px_x < 0 || p.px_y < 0 || p.px_x > g_w || p.px_y > g_h)
		return ;
	vars->map.tiles[p.px_y][p.px_x].v = 1;
	if (vars->map.tiles[p.px_y][p.px_x] == EXIT)
		vars->map.exit_accessible = 1;
	if (vars->map.tiles[p.px_y][p.px_x] == COLLECT)
		vars->map.collectibles++;
	check_path((t_point){p.px_x - 1, p.px_y}, vars);
	check_path((t_point){p.px_x + 1, p.px_y}, vars);
	check_path((t_point){p.px_x, p.px_y - 1}, vars);
	check_path((t_point){p.px_x, p.px_y + 1}, vars);
	return ;
}
