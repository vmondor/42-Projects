/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:52:21 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/13 11:13:26 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	loop_p2(char *currentline, char *line, char *limiter)
{
	if (access("here_doc", F_OK) == -1)
	{
		cleanup_str(currentline, line, limiter);
		perror("Not exist file");
		exit(EXIT_FAILURE);
	}
	ft_printf("%s", line);
}

int	line_is_null(char *line, char *limiter)
{
	if (!line)
	{
		cleanup_str(NULL, line, limiter);
		ft_putstr_fd("\nbash: warning: here-document (wanted `LIMITER')\n", 0);
		return (1);
	}
	return (0);
}

void	cleanup_str(char *str1, char *str2, char *str3)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	if (str3)
		free(str3);
}
