/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:42:57 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 15:04:42 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_path(char **env)
{
	int		i;
	char	*path;
	char	**tab_path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
		{
			path = ft_strdup(env[i]);
			if (!path)
				return ;
			break ;
		}
		i++;
	}
	tab_path = ft_split(path + 5, ':');
	free(path);
	i = 0;
	while (tab_path[i])
	{
		printf("%s\n", tab_path[i]);
		i++;
	}
	ft_free_tab(tab_path);
}
