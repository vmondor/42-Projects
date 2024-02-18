/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:47:33 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/17 20:24:40 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	get_player_bonus(t_bonus *data)
{
	data->i = 0;
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] == 'P')
				return ;
			data->j++;
		}
		data->i++;
	}
}

static int	ft_event_key(int keycode, t_bonus *data)
{
	if (keycode == ESC)
		close_window(data);
	if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_RIGHT || keycode == KEY_LEFT)
	{
        if (data->map[data->i][data->j] == 'E')
			check_exit(data);
		move_player(data, keycode);
        move_enemy(data);
		if (get_collectible(data->map) == 0)
			data->game_won = 1;
	}
	return (0);
}

static int	so_long_bonus(char **map)
{
	t_bonus	data;

	data.count = 0;
	data.game_won = 0;
	data.map = get_map(map);
	data.map_enemy = get_map(map);
	free_tab(map);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	data.win = mlx_new_window(data.mlx, ft_linelen(data.map[0]) * TILE_SIZE,
			ft_tablen(data.map) * TILE_SIZE, "so_long :)");
	if (!data.win)
		return (free(data.mlx), 1);
	init_map_bonus(&data);
	mlx_string_put(data.mlx, data.win, 50, 50, 0x90EE90, "Coup : ");
	get_player_bonus(&data);
    get_pos_enemy(&data);
	mlx_hook(data.win, 2, 1L << 0, ft_event_key, &data);
	// mlx_hook(win, KeyPress, KeyPressMask, key_press, &data);
	// mlx_hook(data.win, DestroyNotify, StructureNotifyMask,
	// 	&close_window, &data);
	/*********** OS ***********/
	mlx_hook(data.win, 17, 0,
		&close_window, &data);
		/*******OS *******/
	mlx_loop(data.mlx);
	return (1);
}
int main(int ac, char **av)
{
	char	**map;
	int		i;

	if (ac != 2)
		error("Il doit y avoir 1 argument", NULL);
	if (!is_filename(av[1]))
		error("Extension invalide", NULL);
	map = content_file_to_tab(av[1]);
	if (!map)
		return (1);
	map_is_valid(map);
	i = 0;
	so_long_bonus(map);
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	return (0);
}