/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:32:43 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/15 14:54:14 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(t_data *data, int i, int j)
{
	if (get_collectible(data->map) == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
			j * TILE_SIZE, (i - 1) * TILE_SIZE);
		data->map[i][j] = '0';
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
			j * TILE_SIZE, i * TILE_SIZE);
		data->count++;
		ft_printf("%d\n", data->count);
		return ;
		data->map[i - 1][j] = 'P';
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
			j * TILE_SIZE, (i - 1) * TILE_SIZE);
		data->map[i][j] = '0';
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
			j * TILE_SIZE, i * TILE_SIZE);
		data->count++;
		ft_printf("%d\n", data->count);
		close_window(data);
	}
	else
		return ;
}