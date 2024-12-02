/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_animated.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:06:32 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/02 15:08:02 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_vars *vars)
{
	static int	frame = 0;
	int			x_offset;
	int			y_offset;

	x_offset = vars->player.pos.px_x * SIZE;
	y_offset = vars->player.pos.px_y * SIZE;
	if (vars->player.direction == 1)
		frame = vars->player.walk_frame;
	else if (vars->player.direction == 0)
		frame = vars->player.walk_frame + 2;
	draw_sprt_to_mem(vars, vars->player.sprite.img_seq[frame], \
		x_offset, y_offset);
}

void	draw_counter(t_vars *vars)
{
	int	digit1;
	int	digit2;
	int	digit3;

	if (vars->moves < 1000)
	{
		digit1 = vars->moves / 100;
		digit2 = (vars->moves % 100) / 10;
		digit3 = vars->moves % 10;
	}
	else
	{
		digit1 = 9;
		digit2 = 9;
		digit3 = 9;
	}
	draw_sprt_to_mem(vars, vars->counter_sp.img_seq[digit1], 0, 0);
	draw_sprt_to_mem(vars, vars->counter_sp.img_seq[digit2], SIZE, 0);
	draw_sprt_to_mem(vars, vars->counter_sp.img_seq[digit3], SIZE * 2, 0);
}

void	draw_victory(t_vars *vars)
{
	int	width;
	int	height;
	int	x_offset;
	int	y_offset;

	width = 150;
	height = 150;
	x_offset = (vars->map.g_w * SIZE - width) / 2;
	y_offset = (vars->map.g_h * SIZE - height) / 2;
	draw_sprt_to_mem(vars, vars->yw_sp.img_seq[0], x_offset, y_offset);
}

void	draw_gameover(t_vars *vars)
{
	int	width;
	int	height;
	int	x_offset;
	int	y_offset;

	width = 150;
	height = 150;
	x_offset = (vars->map.g_w * SIZE - width) / 2;
	y_offset = (vars->map.g_h * SIZE - height) / 2;
	draw_sprt_to_mem(vars, vars->gameover_sp.img_seq[0], x_offset, y_offset);
}
