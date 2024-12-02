/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_load_animated.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:46:17 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/02 15:15:16 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_sprites(t_vars *vars)
{
	char	*player_paths[4];

	player_paths[0] = "img/xpm/knight_right_0.xpm";
	player_paths[1] = "img/xpm/knight_right_1.xpm";
	player_paths[2] = "img/xpm/knight_left_0.xpm";
	player_paths[3] = "img/xpm/knight_left_1.xpm";
	load_sprite(vars, &vars->player.sprite, 4, player_paths);
}

void	load_exit_sprites(t_vars *vars)
{
	char	*exit_paths[2];

	exit_paths[0] = "img/xpm/door-close.xpm";
	exit_paths[1] = "img/xpm/door-open.xpm";
	load_sprite(vars, &vars->e_sp, 2, exit_paths);
}

void	load_counter_sprites(t_vars *vars)
{
	char	*counter_paths[10];

	counter_paths[0] = "img/xpm/0_sp.xpm";
	counter_paths[1] = "img/xpm/1_sp.xpm";
	counter_paths[2] = "img/xpm/2_sp.xpm";
	counter_paths[3] = "img/xpm/3_sp.xpm";
	counter_paths[4] = "img/xpm/4_sp.xpm";
	counter_paths[5] = "img/xpm/5_sp.xpm";
	counter_paths[6] = "img/xpm/6_sp.xpm";
	counter_paths[7] = "img/xpm/7_sp.xpm";
	counter_paths[8] = "img/xpm/8_sp.xpm";
	counter_paths[9] = "img/xpm/9_sp.xpm";
	load_sprite(vars, &vars->counter_sp, 10, counter_paths);
}

void	load_coin_sprites(t_vars *vars)
{
	char	*coin_paths[12];

	coin_paths[0] = "img/xpm/coin_1.xpm";
	coin_paths[1] = "img/xpm/coin_2.xpm";
	coin_paths[2] = "img/xpm/coin_3.xpm";
	coin_paths[3] = "img/xpm/coin_4.xpm";
	coin_paths[4] = "img/xpm/coin_5.xpm";
	coin_paths[5] = "img/xpm/coin_6.xpm";
	coin_paths[6] = "img/xpm/coin_7.xpm";
	coin_paths[7] = "img/xpm/coin_8.xpm";
	coin_paths[8] = "img/xpm/coin_9.xpm";
	coin_paths[9] = "img/xpm/coin_10.xpm";
	coin_paths[10] = "img/xpm/coin_11.xpm";
	coin_paths[11] = "img/xpm/coin_12.xpm";
	load_sprite(vars, &vars->coin.sprite, 12, coin_paths);
}

void	load_enemy_sprites(t_vars *vars)
{
	char	*enemy_paths[4];

	enemy_paths[0] = "img/xpm/slime_1.xpm";
	enemy_paths[1] = "img/xpm/slime_2.xpm";
	enemy_paths[2] = "img/xpm/slime_bad_1.xpm";
	enemy_paths[3] = "img/xpm/slime_bad_2.xpm";
	load_sprite(vars, &vars->enemy.sprite, 4, enemy_paths);
}
