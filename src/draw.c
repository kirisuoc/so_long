/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:12:10 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/01 12:52:59 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_exit(t_vars *vars, int x_offset, int y_offset);

void	draw_background(t_vars *vars)
{
	t_point	pos;

	pos.px_y = 0;
	while (pos.px_y < vars->map.g_h * SIZE)
	{
		pos.px_x = 0;
		while (pos.px_x < vars->map.g_w * SIZE)
		{
			draw_sprt_to_mem(vars, vars->f_sp.img_seq[0], pos.px_x, \
				pos.px_y);
			pos.px_x += SIZE;
		}
		pos.px_y += SIZE;
	}
}

void	draw_map(t_vars *vars)
{
	t_point	s;

	s.px_y = 0;
	while (s.px_y < vars->map.g_h * SIZE)
	{
		s.px_x = 0;
		while (s.px_x < vars->map.g_w * SIZE)
		{
			if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == WALL)
				draw_sprt_to_mem(vars, vars->w_sp.img_seq[0], s.px_x, s.px_y);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == COLLECT)
				draw_sprt_to_mem(vars, vars->c_sp.img_seq[0], s.px_x, s.px_y);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == START)
				draw_sprt_to_mem(vars, vars->s_sp.img_seq[0], s.px_x, s.px_y);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == EXIT)
				draw_exit(vars, s.px_x, s.px_y);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == FLOOR)
				draw_sprt_to_mem(vars, vars->f_sp.img_seq[0], s.px_x, s.px_y);
			s.px_x += SIZE;
		}
		s.px_y += SIZE;
	}
}

static void	draw_exit(t_vars *vars, int x_offset, int y_offset)
{
	if (vars->collected < vars->collectibles)
		draw_sprt_to_mem(vars, vars->e_sp.img_seq[0], x_offset, y_offset);
	else
		draw_sprt_to_mem(vars, vars->e_sp.img_seq[1], x_offset, y_offset);
}

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

void	draw_victory(t_vars *vars)
{
	int	victory_width;
	int	victory_height;
	int	x_offset;
	int	y_offset;

	victory_width = 150;
	victory_height = 150;
	x_offset = (vars->map.g_w * SIZE - victory_width) / 2;
	y_offset = (vars->map.g_h * SIZE - victory_height) / 2;
	draw_sprt_to_mem(vars, vars->yw_sp.img_seq[0], x_offset, y_offset);
}
