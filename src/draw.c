/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:38:02 by erikcousill       #+#    #+#             */
/*   Updated: 2024/11/12 18:28:02 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background(t_vars *vars)
{
	t_point	s;
	t_point	e;

	s.px_x = 0;
	s.px_y = 0;
	e.px_x = vars->map.g_w * SIZE;
	e.px_y = vars->map.g_h * SIZE;
	while (s.px_y < e.px_y)
	{
		while (s.px_x < e.px_x)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->f_sp.img, s.px_x, s.px_y);
			s.px_x += SIZE;
		}
		s.px_x = 0;
		s.px_y += SIZE;
	}
}

void	draw_player(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->p_sp.img, \
			vars->player.pos.px_x * SIZE, vars->player.pos.px_y * SIZE);
}

void	draw_map(t_vars *vars)
{
	t_point	s;

	s.px_x = 0;
	s.px_y = 0;
	while (s.px_y < vars->map.g_h * SIZE)
	{
		while (s.px_x < vars->map.g_w * SIZE)
		{
			ft_printf("Valor en [%d, %d]: %c\n", s.px_y / SIZE, s.px_x / SIZE, vars->map.grid[s.px_y / SIZE][s.px_x / SIZE]);

			if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == WALL)
				put_sp(vars, s, WALL);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == COLLECT)
				put_sp(vars, s, COLLECT);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == START)
				put_sp(vars, s, START);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == EXIT)
				put_sp(vars, s, EXIT);
			else if (vars->map.grid[s.px_y / SIZE][s.px_x / SIZE] == FLOOR)
				put_sp(vars, s, FLOOR);
			s.px_x += SIZE;
		}
		s.px_x = 0;
		s.px_y += SIZE;
	}
}

void	put_sp(t_vars *vars, t_point s, char t)
{

	if (t == WALL)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->w_sp.img, s.px_x, s.px_y);
	else if (t == COLLECT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->c_sp.img, s.px_x, s.px_y);
	else if (t == START)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->s_sp.img, s.px_x, s.px_y);
	else if (t == EXIT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->e_sp.img, s.px_x, s.px_y);
	else if (t == FLOOR)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->f_sp.img, s.px_x, s.px_y);
}
