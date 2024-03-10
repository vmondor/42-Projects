/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:41:53 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/10 20:02:30 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**get_command_exe(char **split_cmd)
{
	char	**args;
	char	*name_prog;
	int		i;

	args = ft_split(split_cmd[0], '/');
	name_prog = ft_strdup(args[ft_tablen(args) - 1]);
	ft_free_tab(args);
	args = malloc(sizeof(char *) * (ft_tablen(split_cmd) + 1));
	args[0] = ft_strdup(name_prog);
	free(name_prog);
	i = 1;
	while (split_cmd[i])
	{
		args[i] = ft_strdup(split_cmd[i]);
		i++;
	}
	args[i] = NULL;
	ft_free_tab(split_cmd);
	return (args);
}

static char	**get_execute_args(char *cmd)
{
	char	**split_cmd;

	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd)
		return (NULL);
	if (cmd[0] == '/')
		return (get_command_exe(split_cmd));
	else
		return (split_cmd);
}

static int	execute_command(t_data *data, char *cmd, char **env)
{
	if (parsing(env, cmd) == 0)
	{
		cleanup(data);
		dup2(STDIN_FILENO, STDOUT_FILENO);
		error("Error: Command not found\n");
	}
	data->args = get_execute_args(cmd);
	if (execve(data->command_to_execute, data->args, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	open_outfile(t_data *data, char **av)
{
	if (ft_strcmp(av[1], "here_doc"))
		data->fd_outfile = open(av[data->ac - 1], O_WRONLY | O_APPEND);
	else
		data->fd_outfile = open(av[data->ac - 1], O_WRONLY);
	if (data->fd_outfile == -1)
		error_outfile(data);
	ft_dup2(data->fd_outfile, STDOUT_FILENO);
	close(data->fd_outfile);
}

void	process_child(t_data *data, char **env, char **av)
{
	init_data(data, env, av[data->nbfork + 2]);
	if (data->nbfork == 0)
	{
		ft_dup2(data->fd_infile, STDIN_FILENO);
		close (data->fd_infile);
	}
	else
		ft_dup2(data->pipefd[data->nbfork - 1][0], STDIN_FILENO);
	if (data->nbfork == 0)
		ft_dup2(data->pipefd[data->nbfork][1], STDOUT_FILENO);
	else if (data->nbfork == (data->ac - 4))
		open_outfile(data, av);
	else
		ft_dup2(data->pipefd[data->nbfork][1], STDOUT_FILENO);
	close_pipefd(data);
	execute_command(data, av[data->nbfork + 2], env);
}
