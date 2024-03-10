/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:03:15 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/10 19:42:26 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	char	**path;

	check_here_doc(ac, av, env);
	if (ac < 5)
		error("Il faut minimum 4 arguments");
	path = get_path(env);
	if (!path)
	{
		error("Pas d'environnement");
		return (1);
	}
	ft_free_tab(path);
	check_access_file(av[1], av[ac - 1]);
	pipex(ac, av, env);
	return (0);
}
