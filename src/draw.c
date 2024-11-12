/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:38:02 by erikcousill       #+#    #+#             */
/*   Updated: 2024/11/12 14:42:18 by erikcousill      ###   ########.fr       */
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
