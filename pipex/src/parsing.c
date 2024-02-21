/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:13:29 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 15:09:19 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_files(int ac, char **av)
{
	int	in_fd;
	// int	out_fd;
	
	(void)ac;
	in_fd = open(av[1], O_RDONLY);
	if (in_fd < 0)
	{
		perror("Fichier infile");
		exit(EXIT_FAILURE);	
	}
	// out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	// if (out_fd < 0)
	// 	perror("Fichier outfil");
}

void	parsing(int ac, char **av, char **env)
{

	(void)env;
	check_files(ac, av);
	// verif commande
}