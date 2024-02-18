/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:51:59 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/17 20:32:03 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    get_pos_enemy(t_bonus *data)
{
    data->enemy_i = 0;
    while (data->map[data->enemy_i])
    {
        data->enemy_j = 0;
        while (data->map[data->enemy_i][data->enemy_j])
        {
            if (data->map[data->enemy_i][data->enemy_j] == 'Z')
                return ;
            data->enemy_j++;
        }
        data->enemy_i++;
    }
}

void    move_enemy(t_bonus *data)
{   
    while (data->map[data->enemy_i][data->enemy_j + 1] != '1')
    {
        if (data->map[data->enemy_i][data->enemy_j] == 'E')
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_z,
                (data->enemy_j + 1) * TILE_SIZE, data->enemy_i * TILE_SIZE);
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->enemy_j * TILE_SIZE, data->enemy_i * TILE_SIZE);
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_e,
                data->enemy_j * TILE_SIZE, data->enemy_i * TILE_SIZE);
            data->enemy_j += 1;
            return ;
        }
        else if (data->map[data->enemy_i][data->enemy_j] == 'C')
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_z,
                (data->enemy_j + 1) * TILE_SIZE, data->enemy_i * TILE_SIZE);
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->enemy_j * TILE_SIZE, data->enemy_i * TILE_SIZE);
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_c,
                data->enemy_j * TILE_SIZE, data->enemy_i * TILE_SIZE);
            data->enemy_j += 1;
            return ;
        }
        else
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_z,
                (data->enemy_j + 1) * TILE_SIZE, data->enemy_i * TILE_SIZE);
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->enemy_j * TILE_SIZE, data->enemy_i * TILE_SIZE);
            data->enemy_j += 1;
            return ;
        }
    }
}