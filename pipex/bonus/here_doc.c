/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:58:26 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/13 11:33:48 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(int ac, char **av, char **env);
char	**perso_args(char **av);

void	check_here_doc(int ac, char **av, char **env)
{
	if (ft_strcmp(av[1], "here_doc") == 0)
		return ;
	else
	{
		if (ac < 6)
			error("Il faut minimum 5 arguments pour here_doc");
		here_doc(ac, av, env);
		exit(0);
	}
}

int	check_limiter(char *line, char *limiter)
{
	if (ft_strcmp(line, limiter))
	{
		cleanup_str(NULL, line, limiter);
		return (1);
	}
	return (0);
}

void	loop_read_stdin(char *currentline, char *limiter)
{
	char *(line) = NULL;
	while (1)
	{
		if (currentline && currentline[ft_strlen(currentline) - 1] == '\n')
			ft_putstr_fd("> ", 0);
		line = get_next_line(0);
		if (!currentline || currentline[ft_strlen(currentline) - 1] != '\n')
		{
			free(currentline);
			currentline = ft_strdup(line);
			free(line);
			continue ;
		}
		if (line_is_null(line, limiter) || check_limiter(line, limiter))
			break ;
		loop_p2(currentline, line, limiter);
		if (line)
		{
			free(currentline);
			currentline = ft_strdup(line);
		}
		free(line);
	}
	free(currentline);
}

void	here_doc(int ac, char **av, char **env)
{
	char	**args;
	int		fd_temp;
	int		fd_stout;
	char	*currentline;
	char	*limiter;

	fd_stout = dup(STDOUT_FILENO);
	fd_temp = open("here_doc", O_RDWR | O_CREAT, 0644);
	ft_dup2(fd_temp, STDOUT_FILENO);
	limiter = get_limiter(av[2]);
	currentline = ft_strdup(limiter);
	loop_read_stdin(currentline, limiter);
	close(fd_temp);
	dup2(fd_stout, STDOUT_FILENO);
	close(fd_stout);
	args = perso_args(av);
	pipex(ac - 1, args, env);
}
