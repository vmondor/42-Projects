/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:35:23 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/15 22:10:54 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	if ((data->map[data->i][data->j] == 'P'
		|| data->map[data->i][data->j] == 'E')
			&& data->map[data->i - 1][data->j] != '1')
	{
		if (data->map[data->i][data->j] == 'E')
			move_from_e(data, data->i - 1, data->j);
		else if (data->map[data->i - 1][data->j] == 'E')
			move_towards_e(data, data->i - 1, data->j);
		else if (data->map[data->i - 1][data->j] != 'E')
			move_towards_other(data, data->i - 1, data->j);
	}
}

void	move_down(t_data *data)
{
	if ((data->map[data->i][data->j] == 'P'
		|| data->map[data->i][data->j] == 'E')
			&& data->map[data->i + 1][data->j] != '1')
	{
		if (data->map[data->i][data->j] == 'E')
			move_from_e(data, data->i + 1, data->j);
		else if (data->map[data->i + 1][data->j] == 'E')
			move_towards_e(data, data->i + 1, data->j);
		else if (data->map[data->i + 1][data->j] != 'E')
			move_towards_other(data, data->i + 1, data->j);
	}
}

void	move_left(t_data *data)
{
	if ((data->map[data->i][data->j] == 'P'
		|| data->map[data->i][data->j] == 'E')
			&& data->map[data->i][data->j - 1] != '1')
	{
		if (data->map[data->i][data->j] == 'E')
			move_from_e(data, data->i, data->j - 1);
		else if (data->map[data->i][data->j - 1] == 'E')
			move_towards_e(data, data->i, data->j - 1);
		else if (data->map[data->i][data->j - 1] != 'E')
			move_towards_other(data, data->i, data->j - 1);
	}
}

void	move_right(t_data *data)
{
	if ((data->map[data->i][data->j] == 'P'
		|| data->map[data->i][data->j] == 'E')
			&& data->map[data->i][data->j + 1] != '1')
	{
		if (data->map[data->i][data->j] == 'E')
			move_from_e(data, data->i, data->j + 1);
		else if (data->map[data->i][data->j + 1] == 'E')
			move_towards_e(data, data->i, data->j + 1);
		else if (data->map[data->i][data->j + 1] != 'E')
			move_towards_other(data, data->i, data->j + 1);
	}
}

void	move_player(t_data *data, int keycode)
{
	if (keycode == KEY_UP)
		move_up(data);
	if (keycode == KEY_DOWN)
		move_down(data);
	if (keycode == KEY_LEFT)
		move_left(data);
	if (keycode == KEY_RIGHT)
		move_right(data);
}
