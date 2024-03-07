/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:12:34 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 12:17:29 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	pid_t	pid = fork();

	if (pid == 0)
	{
		printf("Je suis l'enfant, PID = %d\n", getpid());
	}
	else if (pid > 0)
	{
		wait(NULL);
		printf("Je suis le parent, PID = %d\n", getpid());
	}
	else
	{
		perror("fork");
		return (1);
	}
	return (0);
}