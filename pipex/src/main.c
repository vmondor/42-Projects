/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:03:15 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/05 16:03:23 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	char	**path;
	int		i;

	if (ac != 5)
		error("Il faut 4 arguments");
	path = get_path(env);
	if (!path)
	{
		error("Pas d'environnement");
		return (1);
	}
	ft_free_tab(path);
	check_access_file(av[1], av[ac - 1]);
	i = 2;
	while (i < ac - 1)
	{
		if (parsing(env, av[i]) == 0)
			error("Command not found");
		i++;
	}
	pipex(ac, av, env);
	return (0);
}
