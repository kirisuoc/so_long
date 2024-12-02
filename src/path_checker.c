/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:10:27 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/29 11:04:05 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_point p, t_vars *vars)
{
	size_t	g_w;
	size_t	g_h;

	g_w = vars->map.g_w;
	g_h = vars->map.g_h;
	if (vars->map.grid[p.px_y][p.px_x] == WALL || \
			vars->map.tiles[p.px_y][p.px_x].v == 1 || \
			p.px_x > g_w || p.px_y > g_h)
		return ;
	vars->map.tiles[p.px_y][p.px_x].v = 1;
	if (vars->map.grid[p.px_y][p.px_x] == EXIT)
		vars->map.exit_accessible = 1;
	if (vars->map.grid[p.px_y][p.px_x] == COLLECT)
		vars->map.accessible_collectibles++;
	check_path((t_point){p.px_x - 1, p.px_y}, vars);
	check_path((t_point){p.px_x + 1, p.px_y}, vars);
	check_path((t_point){p.px_x, p.px_y - 1}, vars);
	check_path((t_point){p.px_x, p.px_y + 1}, vars);
	return ;
}
