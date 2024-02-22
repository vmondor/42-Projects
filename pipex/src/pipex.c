/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:54:00 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 19:18:27 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_args(char **cmd1, char *filename)
{
	char	**args;
	int		i;

	args = malloc(sizeof(char *) * (ft_tablen(cmd1) + 2));
	if (!args)
		return (0);
	i = 0;
	while (cmd1[i])
	{
		args[i] = ft_strdup(cmd1[i]);
		i++;
	}
	args[i] = ft_strdup(filename);
	i++;
	args[i] = NULL;
	ft_free_tab(cmd1);
	return (args);
}

int	execve_cmd(char **path, char **args)
{
	int	i;

	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], args[0]);
		i++;
	}
	i = 0;
	while (path[i])
	{
		execve(path[i], args, NULL);
		i++;
	}
	ft_free_tab(args);
	ft_free_tab(path);
	return (0);
}
// int execve_cmd_2()
// {
//     const char *path = "/bin/ls";

	// char *const args[] = {"ls", "-l", "./src", NULL};

//     if (execve(path, args, NULL) == -1) {
//         perror("execve");
//         exit(EXIT_FAILURE);
//     }
//     return 0;
// }

void	pipex(char **av, char **env, char **cmd1)
{
	char	**path;
	char	**args;

	path = get_path(env);
	if (!path)
		return ;
	args = get_args(cmd1, av[1]);
	execve_cmd(path, args);
}
