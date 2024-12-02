/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:23:59 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/02 15:13:05 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_position(t_vars *vars, t_point np);
static void	update_player_animation(t_vars *vars, int direction);
static void	update_current_moves(t_vars *vars, t_point np);

void	move_player(t_vars *vars, int new_x, int new_y, int direction)
{
	update_player_position(vars, (t_point){new_x, new_y});
	update_player_animation(vars, direction);
}

static void	update_player_position(t_vars *vars, t_point np)
{
	if (np.px_x < vars->map.g_w && np.px_y < vars->map.g_h)
	{
		if (vars->game_over || vars->won)
			return ;
		if (vars->map.grid[np.px_y][np.px_x] == COLLECT)
		{
			vars->collected++;
			vars->map.grid[np.px_y][np.px_x] = FLOOR;
			if (vars->collected == vars->collectibles)
				vars->exit_unlocked = TRUE;
			vars->player.pos = np;
		}
		else if (vars->map.grid[np.px_y][np.px_x] == ENEMY)
			vars->game_over = TRUE;
		else if (vars->map.grid[np.px_y][np.px_x] == EXIT)
		{
			vars->player.pos = np;
			if (vars->exit_unlocked)
				vars->won = TRUE;
		}
		else if (vars->map.grid[np.px_y][np.px_x] == START || \
			vars->map.grid[np.px_y][np.px_x] == FLOOR)
			vars->player.pos = np;
		update_current_moves(vars, np);
	}
}

static void	update_player_animation(t_vars *vars, int direction)
{
	if (direction == 0 || direction == 1)
		vars->player.direction = direction;
	vars->player.walk_frame = (vars->player.walk_frame + 1) % 2;
}

static void	update_current_moves(t_vars *vars, t_point np)
{
	if (np.px_x < vars->map.g_w && np.px_y < vars->map.g_h)
	{
		if ((vars->map.grid[np.px_y][np.px_x] == COLLECT) \
			|| (vars->map.grid[np.px_y][np.px_x] == EXIT) \
			|| (vars->map.grid[np.px_y][np.px_x] == START) \
			|| (vars->map.grid[np.px_y][np.px_x] == FLOOR))
			vars->moves++;
	}
}
