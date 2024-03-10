/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:54:00 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/07 20:15:23 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	before_start(t_data *data, int ac, char **av)
{
	data->ac = ac;
	init_pipe(data);
	init_pids(data);
	data->fd_infile = open(av[1], O_RDONLY);
	if (data->fd_infile == -1)
		return ;
}

static void	wait_child(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->ac - 3))
		waitpid(data->pids[i++], NULL, 0);
}

void	close_all(t_data *data)
{
	close(data->fd_infile);
	close_pipefd(data);
	wait_child(data);
	free_pipefd(data);
	free(data->pids);
}

void	pipex(int ac, char **av, char **env)
{
	t_data	data;
	pid_t	pid;

	before_start(&data, ac, av);
	data.nbfork = 0;
	while (data.nbfork < (data.ac - 3))
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
			process_child(&data, env, av);
		else
			data.pids[data.nbfork] = pid;
		data.nbfork++;
	}
	close_all(&data);
	if (ft_strcmp(av[1], "here_doc"))
	{
		ft_free_tab(av);
		unlink("here_doc");
	}
}
