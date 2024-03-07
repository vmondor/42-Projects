/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:13:29 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/05 15:59:56 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	command_exist(char **env, char *cmd)
{
	char	**path;

	int (i) = 0;
	path = get_path(env);
	if (!path)
		return (0);
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd);
		i++;
	}
	i = 0;
	while (path[i])
	{
		if (access(path[i], F_OK) == 0)
		{
			ft_free_tab(path);
			return (1);
		}
		i++;
	}
	return (ft_free_tab(path), 0);
}

int	parsing(char **env, char *cmd)
{
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
		return (0);
	if (cmd[0] == '/')
	{
		if (access(args[0], F_OK) == -1)
		{
			ft_free_tab(args);
			return (0);
		}
	}
	else
	{
		if (command_exist(env, args[0]) == 0)
		{
			ft_free_tab(args);
			return (0);
		}
	}
	ft_free_tab(args);
	return (1);
}
