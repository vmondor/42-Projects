/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:03:15 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 19:35:42 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	char	**cmd1;

	if (ac != 5)
		error("Il faut 4 arguments");
	parsing(ac, av);
	ft_printf("\n");
	ft_printf("***********\n");
	cmd1 = ft_split(av[2], ' ');
	if (!cmd1)
		return (1);
	pipex(av, env, cmd1);
	ft_printf("***** END *****\n");
	return (0);
}
