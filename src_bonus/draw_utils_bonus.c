/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:03:35 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/02 12:09:55 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_sprite_size(t_vars *vars, void *sprite_img, int *sprite_width, \
		int *sprite_height);

void	draw_sprt_to_mem(t_vars *vars, void *sprite_img, int x_offset, \
		int y_offset)
{
	int		sprite_width;
	int		sprite_height;
	char	*sprite_data;
	int		i;
	int		j;

	get_sprite_size(vars, sprite_img, &sprite_width, &sprite_height);
	sprite_data = mlx_get_data_addr(sprite_img, &vars->bits_per_pixel, \
		&vars->line_length, &vars->endian);
	i = 0;
	while (i < sprite_width)
	{
		j = 0;
		while (j < sprite_height)
		{
			*(unsigned int *)(vars->addr + ((y_offset + j) * vars->map.g_w \
			* SIZE + (x_offset + i)) * (vars->bits_per_pixel / 8)) \
			= *(unsigned int *)(sprite_data + (j * sprite_width + i) \
			* (vars->bits_per_pixel / 8));
			j++;
		}
		i++;
	}
}

static void	get_sprite_size(t_vars *vars, void *sprite_img, int *sprite_width, \
		int *sprite_height)
{
	*sprite_width = SIZE;
	*sprite_height = SIZE;
	if (sprite_img == vars->yw_sp.img_seq[0])
	{
		*sprite_width = vars->yw_sp.px_w;
		*sprite_height = vars->yw_sp.px_h;
	}
	else if (sprite_img == vars->gameover_sp.img_seq[0])
	{
		*sprite_width = vars->gameover_sp.px_w;
		*sprite_height = vars->gameover_sp.px_h;
	}
}
