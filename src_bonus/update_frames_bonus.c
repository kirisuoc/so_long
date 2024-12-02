/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:11:11 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/02 15:13:05 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_coin_frames(t_vars *vars)
{
	int	update_rate;
	int	map_area;

	map_area = vars->map.g_w * vars->map.g_h;
	update_rate = (int)(-0.3 * map_area + 130.725);
	if (update_rate < 10)
		update_rate = 10;
	if (vars->tick % update_rate == 0)
		vars->coin.frame = (vars->coin.frame + 1) % 12;
}

void	update_enemy_frames(t_vars *vars)
{
	int	update_rate;
	int	map_area;

	map_area = vars->map.g_w * vars->map.g_h;
	update_rate = (int)(-0.25 * map_area + 130.725);
	if (vars->tick % update_rate == 0)
	{
		if (vars->game_over)
			vars->enemy.frame = (vars->enemy.frame + 1) % 2 + 2;
		else
			vars->enemy.frame = (vars->enemy.frame + 1) % 2;
	}
}
