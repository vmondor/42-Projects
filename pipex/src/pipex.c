/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:54:00 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/06 10:48:31 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	before_start(t_data *data, int ac, char **av)
{
	(void)av;
	data->ac = ac;
	init_pipe(data);
	init_pids(data);
}

static void	wait_child(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->ac - 3))
		waitpid(data->pids[i++], NULL, 0);
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
	close_pipefd(&data);
	wait_child(&data);
	free_pipefd(&data);
	free(data.pids);
}
