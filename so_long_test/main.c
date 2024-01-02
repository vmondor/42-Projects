/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:27:00 by vmondor           #+#    #+#             */
/*   Updated: 2024/01/02 14:39:31 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_strcopy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	floodFill(char	**tab, int x, int y)
{
	if (tab[x][y] == '0')
	{
		floodFill(tab, x+1, y);
		floodFill(tab, x+1, y);
		floodFill(tab, x, y+1);
		floodFill(tab, x, y-1);
	}
	if (tab[x][y] == 'E')
		return (1);
	return (0);
}

int	main(void)
{
	int		fd;
	int		i;
	int		index;
	char	*res;
	char	**tab;
	int		flag;

	index = 0;
	fd = open("map.txt", O_RDONLY);
	tab = malloc(sizeof(char *) * 1000);
	while ((res = get_next_line(fd)))
	{
		tab[index] = malloc(sizeof(char) * 1000);
		ft_strcopy(tab[index], res);
		index++;
		free(res);
	}
	tab[index] = NULL;
	i = 0;
	while (tab[i])
	{
		printf("tab[%d] : %s", i, tab[i]);
		i++;
	}
	
	flag = floodFill(tab, 1, 1);
	if (flag)
		printf("\n\nMap valide");
	else
		printf("\n\nMap invalide");
	return (0);
}