/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:02:18 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/07 16:05:38 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_dup2(int file_dest, int file_src)
{
	int	dup;

	dup = dup2(file_dest, file_src);
	if (dup == -1)
	{
		perror("Error dup2");
		exit(EXIT_FAILURE);
	}
}

void	check_access_file(char *infile, char *outfile)
{
	if (access(infile, F_OK) == -1)
	{
		perror("Error infile");
		exit(EXIT_FAILURE);
	}
	if (access(infile, R_OK) == -1)
	{
		perror("Error infile");
		exit(EXIT_FAILURE);
	}
	if (access(outfile, F_OK) == 0 && access(outfile, W_OK) == -1)
	{
		perror("Error outfile");
		exit(EXIT_FAILURE);
	}
}

int	open_infile(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	close_pipefd(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ac - 4)
	{
		close(data->pipefd[i][0]);
		close(data->pipefd[i][1]);
		i++;
	}
}

void	cleanup(t_data *data)
{
	if (data->path)
		ft_free_tab(data->path);
	if (data->args)
		ft_free_tab(data->args);
}
