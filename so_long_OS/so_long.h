/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:12:03 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/15 14:32:50 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_UP 13
// # define KEY_UP 126
# define KEY_DOWN 1
// # define KEY_DOWN 125
# define KEY_LEFT 0
// # define KEY_LEFT 123
# define KEY_RIGHT 2
// # define KEY_RIGHT 124
# define ESC 53
# define WIDTH 2500
# define HEIGHT 1300
# define TILE_SIZE 100

# include "mlx/mlx.h"
# include "libft/ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <unistd.h> // write
# include <stdlib.h> // malloc
// # include <X11/X.h>
// # include <X11/keysym.h> // try to delete
# include <fcntl.h> // open
// # include <stdio.h> // remove for push

typedef struct s_img
{
	void	*img_0;
	void	*img_p;
	void	*img_e;
	void	*img_c;
	void	*img_1;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		count;
    int     i;
    int     j;
	t_img	img;
}				t_data;

/* FILE_TO_TAB */
char	**content_file_to_tab(char *str);

/* GET_ITEMS */
char	**get_map(char **map);
int		get_collectible(char **map);
int		get_exit(char **map);

/* CHECK_MAP_UTILS */
int		ft_strcmp(char *s1, char *s2);
int		is_rectangle(char **map);
int		is_close(char **map);
int		more_items(char **tab);
int		correct_items_in_map(char **tab);

/* CHECK MAP */
void	map_is_valid(char **map);

/* UTILS */
int		is_filename(char *filename);
int		ft_strlen(char *s);
int		ft_linelen(char *s);
int		ft_tablen(char **tab);
void	free_tab(char **tab);

/* ERROR */
void	error(char *str, char **tab);

/***** GAME *****/
int		so_long(char **map);

/* CLOSE */
int		close_window(t_data *data);

/* SO_LONG */
void	init_map(t_data *data);
// char	*ft_putnbr(int nbr);

/* GAME */
void	move_player(t_data *data, int keycode);
void	get_player(t_data *data);
void    check_exit(t_data *data, int i, int j);


#endif
