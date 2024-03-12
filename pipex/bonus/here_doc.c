/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:58:26 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/12 10:33:48 by vmondor          ###   ########.fr       */
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

char	*get_limiter(char *str)
{
	char	*limiter;
	int		i;

	limiter = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!limiter)
		return (NULL);
	i = 0;
	while (str[i])
	{
		limiter[i] = str[i];
		i++;
	}
	limiter[i] = '\n';
	i++;
	limiter[i] = '\0';
	return (limiter);
}

void	loop_read_stdin(char **av)
{
	char	*line;
	char	*limiter;

	limiter = get_limiter(av[2]);
	while (1)
	{
		ft_putstr_fd("> ", 0);
		line = get_next_line(0);
		if (ft_strcmp(line, limiter))
		{
			free(line);
			free(limiter);
			break ;
		}
		if (access("here_doc", F_OK) == -1)
		{
			free(line);
			free(limiter);
			perror("Not exist file");
			exit(EXIT_FAILURE);
		}
		ft_printf("%s", line);
		free(line);
	}
}

void	here_doc(int ac, char **av, char **env)
{
	char	**args;
	int		fd_temp;
	int		fd_stout;

	fd_stout = dup(STDOUT_FILENO);
	fd_temp = open("here_doc", O_RDWR | O_CREAT, 0644);
	ft_dup2(fd_temp, STDOUT_FILENO);
	loop_read_stdin(av);
	close(fd_temp);
	dup2(fd_stout, STDOUT_FILENO);
	close(fd_stout);
	args = perso_args(av);
	pipex(ac - 1, args, env);
}

char	**perso_args(char **av)
{
	char	**args;
	int		i;
	int		j;

	args = malloc(sizeof(char *) * (ft_tablen(av)));
	if (!args)
		return (NULL);
	i = 0;
	j = 0;
	while (av[i])
	{
		if (i == 2)
			i++;
		args[j] = ft_strdup(av[i]);
		i++;
		j++;
	}
	args[j] = NULL;
	return (args);
}
