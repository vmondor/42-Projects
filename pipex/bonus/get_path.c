/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:42:57 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/03 16:03:34 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_path(char **env)
{
	int		i;
	char	*path_str;
	char	**path;

	i = 0;
	path_str = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
		{
			path_str = ft_strdup(env[i]);
			if (!path_str)
				return (NULL);
			break ;
		}
		i++;
	}
	if (!path_str)
		return (NULL);
	path = ft_split(path_str + 5, ':');
	if (!path)
		return (NULL);
	free(path_str);
	return (path);
}

static void	compare_with_absolute(t_data *data)
{
	int	i;

	i = 0;
	if (access(data->args[0], F_OK) == 0)
		data->command_to_execute = data->args[0];
	else
		data->command_to_execute = NULL;
}

static int	compare_with_relative(t_data *data)
{
	int	i;

	i = 0;
	while (data->path[i])
	{	
		data->path[i] = ft_strjoin(data->path[i], "/");
		data->path[i] = ft_strjoin(data->path[i], data->args[0]);
		if (access(data->path[i], F_OK) == 0)
		{
			data->command_to_execute = data->path[i];
			return (1);
		}
		i++;
	}
	data->command_to_execute = NULL;
	return (1);
}

void	get_command_path(t_data *data)
{
	if (data->args[0][0] == '/')
		compare_with_absolute(data);
	else
		compare_with_relative(data);
}
