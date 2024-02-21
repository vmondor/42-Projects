/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:03:15 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 14:59:13 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	// int	i;

	if (ac != 5)
		error("Il faut 4 arguments");
	parsing(ac, av, env);
	get_path(env);

	// i = 0;
	// while (env[i])
	// {
	// 	ft_printf("%s\n", env[i]);
	// 	i++;
	// }
	return (0);
}
