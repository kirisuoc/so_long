/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:06:56 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/02 16:44:12 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_sprite(t_sprite *sprite, void *mlx);

void	free_tiles(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < vars->map.g_h)
	{
		free(vars->map.tiles[i]);
		vars->map.tiles[i] = NULL;
		i++;
	}
	free(vars->map.tiles);
	vars->map.tiles = NULL;
}

void	free_map(t_vars *vars)
{
	size_t	i;

	if (vars->map.grid)
	{
		i = 0;
		while (i < vars->map.g_h)
		{
			free(vars->map.grid[i]);
			i++;
		}
		free(vars->map.grid);
		vars->map.grid = NULL;
	}
	if (vars->map.tiles)
	{
		i = 0;
		while (i < vars->map.g_h)
		{
			free(vars->map.tiles[i]);
			i++;
		}
		free(vars->map.tiles);
		vars->map.tiles = NULL;
	}
}

void	free_graphics(t_vars *vars)
{
	if (vars->img)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		vars->img = NULL;
	}
	if (vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		vars->mlx = NULL;
	}
}

void	free_sprites(t_vars *vars)
{
	free_sprite(&vars->f_sp, vars->mlx);
	free_sprite(&vars->w_sp, vars->mlx);
	free_sprite(&vars->s_sp, vars->mlx);
	free_sprite(&vars->e_sp, vars->mlx);
	free_sprite(&vars->c_sp, vars->mlx);
	free_sprite(&vars->yw_sp, vars->mlx);
	free_sprite(&vars->player.sprite, vars->mlx);
}

static void	free_sprite(t_sprite *sprite, void *mlx)
{
	int	i;

	if (sprite && sprite->img_seq)
	{
		i = 0;
		while (i < sprite->num_sprites)
		{
			if (sprite->img_seq[i])
				mlx_destroy_image(mlx, sprite->img_seq[i]);
			i++;
		}
		free(sprite->img_seq);
		sprite->img_seq = NULL;
	}
}
