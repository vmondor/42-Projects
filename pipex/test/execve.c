/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:07:36 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/20 14:29:20 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	char	*args[] = {"/bin/ls", "-l", NULL};

	if (execve("/bin/ls", args, NULL) == -1)
	if (execve("/bin/av[2]", args, NULL) == -1)
		perror("Erreur");
	return (0);
}

PATH + av[2] = str;

execve(str, args. NULL);