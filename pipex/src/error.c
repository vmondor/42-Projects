/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:02:16 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/06 17:57:12 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pipefd(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ac - 4)
	{
		free(data->pipefd[i]);
		i++;
	}
	free(data->pipefd);
}

void	error_outfile(t_data *data)
{
	cleanup(data);
	free_pipefd(data);
	free(data->pids);
	error("Outfile");
	exit(EXIT_FAILURE);
}

void	error_pid(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	perror("fork");
	exit(EXIT_FAILURE);
}

void	error(char *str)
{
	if (!str)
		str = " ";
	ft_printf("Error\n");
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
