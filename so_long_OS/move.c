/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:35:23 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/13 19:15:24 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i - 1][j] != '1')
			{
				data->map[i - 1][j] = 'P';
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
					j * TILE_SIZE, (i - 1) * TILE_SIZE);
				data->map[i][j] = '0';
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
					j * TILE_SIZE, i * TILE_SIZE);
				data->count++;
				ft_printf("%d\n", data->count);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_down(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i + 1][j] != '1')
			{
				data->map[i + 1][j] = 'P';
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
					j * TILE_SIZE, (i + 1) * TILE_SIZE);
				data->map[i][j] = '0';
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
					j * TILE_SIZE, i * TILE_SIZE);
				data->count++;
				ft_printf("%d\n", data->count);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i][j - 1] != '1')
			{
				data->map[i][j - 1] = 'P';
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
					(j - 1) * TILE_SIZE, i * TILE_SIZE);
				data->map[i][j] = '0';
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
					j * TILE_SIZE, i * TILE_SIZE);
				data->count++;
				ft_printf("%d\n", data->count);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_right(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i][j + 1] != '1')
			{
				data->map[i][j + 1] = 'P';
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
					(j + 1) * TILE_SIZE, i * TILE_SIZE);
				data->map[i][j] = '0';
				mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
					j * TILE_SIZE, i * TILE_SIZE);
				data->count++;
				ft_printf("%d\n", data->count);
				return ;
			}
			j++;
		}
		i++;
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
