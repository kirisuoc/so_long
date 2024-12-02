/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:12:10 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/02 15:07:26 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_exit(t_vars *vars, int x_offset, int y_offset);
static void	draw_coin(t_vars *vars, int x_offset, int y_offset);
static void	draw_enemy(t_vars *vars, int x_offset, int y_offset);

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
				draw_coin(vars, s.px_x, s.px_y);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == START)
				draw_sprt_to_mem(vars, vars->s_sp.img_seq[0], s.px_x, s.px_y);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == EXIT)
				draw_exit(vars, s.px_x, s.px_y);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == FLOOR)
				draw_sprt_to_mem(vars, vars->f_sp.img_seq[0], s.px_x, s.px_y);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == ENEMY)
				draw_enemy(vars, s.px_x, s.px_y);
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

static void	draw_coin(t_vars *vars, int x_offset, int y_offset)
{
	draw_sprt_to_mem(vars, vars->coin.sprite.img_seq[vars->coin.frame], \
		x_offset, y_offset);
}

static void	draw_enemy(t_vars *vars, int x_offset, int y_offset)
{
	draw_sprt_to_mem(vars, vars->enemy.sprite.img_seq[vars->enemy.frame], \
		x_offset, y_offset);
}
