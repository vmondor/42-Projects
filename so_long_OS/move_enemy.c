/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:51:59 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/16 12:59:29 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    move_enemy(t_bonus *data)
{
	if ((data->map[data->i][data->j] == 'Z'
		|| data->map[data->i][data->j] == 'E')
			&& data->map[data->i + 1][data->j] != '1')
	{
		if (data->map[data->i + 1][data->j] != 'E')
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_z,
                data->j * TILE_SIZE, data->i + 1 * TILE_SIZE);
            data->map[data->i][data->j] = '0';
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            ft_printf("%d\n", data->count);
            data->i = data->i + 1;
            data->j = data->j;
            return ;
        }
	}
}