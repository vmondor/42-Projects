/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:17:19 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/06 20:15:14 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_pipe(t_data *data)
{
	int	i;

	i = 0;
	data->pipefd = malloc(sizeof(int *) * (data->ac - 4));
	if (!data->pipefd)
		exit(EXIT_FAILURE);
	while (i < data->ac - 4)
	{
		data->pipefd[i] = malloc(sizeof(int) * 2);
		if (pipe(data->pipefd[i]) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	init_pids(t_data *data)
{
	data->pids = malloc(sizeof(pid_t) * (data->ac - 3));
	if (!data->pids)
	{
		perror("pids");
		exit(EXIT_FAILURE);
	}
}

void	init_data(t_data *data, char **env, char *cmd)
{
	data->path = get_path(env);
	if (!data->path)
		exit(EXIT_FAILURE);
	data->args = ft_split(cmd, ' ');
	if (!data->args)
	{
		ft_free_tab(data->path);
		ft_free_tab(data->cmds);
		exit(EXIT_FAILURE);
	}
	get_command_path(data);
}
