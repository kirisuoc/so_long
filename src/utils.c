/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:48:20 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/19 15:00:05 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int key_handler(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == 53 || keycode == 65307)
		close_window(vars);
	else if((keycode == 2 || keycode == 100 || keycode == 124 || keycode == 65363) && !vars->won)
		update_player_position(vars, (t_point){vars->player.pos.px_x + 1, vars->player.pos.px_y});
	else if((keycode == 0 || keycode == 97 || keycode == 123 || keycode == 65361) && !vars->won)
		update_player_position(vars, (t_point){vars->player.pos.px_x - 1, vars->player.pos.px_y});
	else if((keycode == 13 || keycode == 119 || keycode == 126 || keycode == 65362) && !vars->won)
		update_player_position(vars, (t_point){vars->player.pos.px_x, vars->player.pos.px_y - 1});
	else if((keycode == 1 || keycode == 115 || keycode == 125 || keycode == 65364) && !vars->won)
		update_player_position(vars, (t_point){vars->player.pos.px_x, vars->player.pos.px_y + 1});
	return (0);
}

size_t	ft_linelen(char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

int	check_map_name(char *s)
{
	size_t	l;

	l = ft_strlen(s) - 1;
	if (s[l] == 'r' && s[l - 1] == 'e' && s[l - 2] == 'b' && s[l - 3] == '.')
		return (0);
	return (1);
}
