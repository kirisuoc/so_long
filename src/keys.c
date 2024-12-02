/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:23:15 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/29 16:50:06 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_key_right(int keycode);
static int	is_key_left(int keycode);
static int	is_key_up(int keycode);
static int	is_key_down(int keycode);

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == 53 || keycode == 65307)
		close_window(vars);
	else if ((is_key_right(keycode)) && !vars->won)
	{
		move_player(vars, vars->player.pos.px_x + 1, vars->player.pos.px_y, 1);
	}
	else if ((is_key_left(keycode) && !vars->won))
	{
		move_player(vars, vars->player.pos.px_x - 1, vars->player.pos.px_y, 0);
	}
	else if ((is_key_up(keycode) && !vars->won))
	{
		move_player(vars, vars->player.pos.px_x, vars->player.pos.px_y - 1, -1);
	}
	else if ((is_key_down(keycode) && !vars->won))
	{
		move_player(vars, vars->player.pos.px_x, vars->player.pos.px_y + 1, -1);
	}
	return (0);
}

static int	is_key_right(int keycode)
{
	return (keycode == 2 || keycode == 100 \
		|| keycode == 124 || keycode == 65363);
}

static int	is_key_left(int keycode)
{
	return (keycode == 0 || keycode == 97
		|| keycode == 123 || keycode == 65361);
}

static int	is_key_up(int keycode)
{
	return (keycode == 13 || keycode == 119 \
		|| keycode == 126 || keycode == 65362);
}

static int	is_key_down(int keycode)
{
	return (keycode == 1 || keycode == 115 \
		|| keycode == 125 || keycode == 65364);
}
