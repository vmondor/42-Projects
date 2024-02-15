/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:35:23 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/15 18:05:40 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
    if ((data->map[data->i][data->j] == 'P' || data->map[data->i][data->j] == 'E') && data->map[data->i - 1][data->j] != '1')
    {
        if (data->map[data->i][data->j] == 'E')
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_e,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
                data->j * TILE_SIZE, (data->i - 1) * TILE_SIZE);
            data->map[data->i - 1][data->j] = 'P';
            data->count++;
            data->i--;
        }
        else if (data->map[data->i - 1][data->j] == 'E')
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
                data->j * TILE_SIZE, (data->i - 1) * TILE_SIZE);
            data->map[data->i][data->j] = '0';
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            data->count++;
            data->i--;
        }
        else if (data->map[data->i - 1][data->j] != 'E')
        {
            data->map[data->i - 1][data->j] = 'P';
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
                data->j * TILE_SIZE, (data->i - 1) * TILE_SIZE);
            data->map[data->i][data->j] = '0';
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            data->count++;
            data->i--;
        }
        ft_printf("%d\n", data->count);
    }
}

void	move_down(t_data *data)
{
    if ((data->map[data->i][data->j] == 'P'  || data->map[data->i][data->j] == 'E') && data->map[data->i + 1][data->j] != '1')
    {
        if (data->map[data->i][data->j] == 'E')
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_e,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
                data->j * TILE_SIZE, (data->i + 1) * TILE_SIZE);
            data->map[data->i + 1][data->j] = 'P';
            data->count++;
            ft_printf("%d\n", data->count);
            data->i++;
            return ;
        }
        else if (data->map[data->i + 1][data->j] == 'E')
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
                data->j * TILE_SIZE, (data->i + 1) * TILE_SIZE);
            data->map[data->i][data->j] = '0';
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            data->count++;
            ft_printf("%d\n", data->count);
            data->i++;
            return ;
        }
        else if (data->map[data->i + 1][data->j] != 'E')
        {
            data->map[data->i + 1][data->j] = 'P';
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
                data->j * TILE_SIZE, (data->i + 1) * TILE_SIZE);
            data->map[data->i][data->j] = '0';
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            data->count++;
            ft_printf("%d\n", data->count);
            data->i++;
            return ;
        }
    }
}

void	move_left(t_data *data)
{
    if ((data->map[data->i][data->j] == 'P'  || data->map[data->i][data->j] == 'E') && data->map[data->i][data->j - 1] != '1')
    {
        if (data->map[data->i][data->j] == 'E')
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_e,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
                (data->j - 1) * TILE_SIZE, data->i * TILE_SIZE);
            data->map[data->i][data->j - 1] = 'P';
            data->count++;
            ft_printf("%d\n", data->count);
            data->j--;
            return ;
        }
        else if (data->map[data->i][data->j - 1] == 'E')
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
                (data->j - 1) * TILE_SIZE, data->i * TILE_SIZE);
            data->map[data->i][data->j] = '0';
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            data->count++;
            ft_printf("%d\n", data->count);
            data->j--;
            return ;
        }
        else if (data->map[data->i][data->j - 1] != 'E')
        {
            data->map[data->i][data->j - 1] = 'P';
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
                (data->j - 1) * TILE_SIZE, data->i * TILE_SIZE);
            data->map[data->i][data->j] = '0';
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            data->count++;
            ft_printf("%d\n", data->count);
            data->j--;
            return ;
        }
    }
}

void	move_right(t_data *data)
{
    if ((data->map[data->i][data->j] == 'P'  || data->map[data->i][data->j] == 'E') && data->map[data->i][data->j + 1] != '1')
    {
        if (data->map[data->i][data->j] == 'E')
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_e,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
                (data->j + 1) * TILE_SIZE, data->i * TILE_SIZE);
            data->map[data->i][data->j + 1] = 'P';
            data->count++;
            ft_printf("%d\n", data->count);
            data->j++;
            return ;
        }
        else if (data->map[data->i][data->j + 1] == 'E')
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
                (data->j + 1) * TILE_SIZE, data->i * TILE_SIZE);
            data->map[data->i][data->j] = '0';
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            data->count++;
            ft_printf("%d\n", data->count);
            data->j++;
            return ;
        }
        else if (data->map[data->i][data->j + 1] != 'E')
        {
            data->map[data->i][data->j + 1] = 'P';
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_p,
                (data->j + 1) * TILE_SIZE, data->i * TILE_SIZE);
            data->map[data->i][data->j] = '0';
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_0,
                data->j * TILE_SIZE, data->i * TILE_SIZE);
            data->count++;
            ft_printf("%d\n", data->count);
            data->j++;
            return ;
        }
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
    check_exit(data);
}
