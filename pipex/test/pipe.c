/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:35:06 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 13:11:55 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	main(void)
// {
// 	int		pipefd[2];
// 	char	buf;

// 	printf("MAIN 1\n");
// 	if (pipe(pipefd) == -1)
// 	{
// 		perror("pipe");
// 		exit(2);
// 	}
// 	pid_t	pid = fork();
// 	printf("MAIN 2\n");
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(2);
// 	}
// 	else  if (pid == 0)
// 	{
// 		printf("PID == 0\n");
// 		// Enfant lit depuis le pipe
// 		close(pipefd[1]); // Ferme l'extremite inutilisee d'ecriture
// 		while (read(pipefd[0], &buf, 1) > 0)
// 		{
// 			write(1, &buf, 1);
// 		}
// 		write(1, "LA\n", 3);
// 		close(pipefd[0]);
// 		exit(2);
// 	}
// 	else
// 	{
// 		printf("ICI\n");
// 		// Parent : ecrit dans le pipe
// 		close(pipefd[0]); // Ferme l'extremite unitilisee d'ecriture
// 		write(pipefd[1], "Hello, child!", 13);
// 		close(pipefd[1]); // Signal EOF aux lecteurs du pipe
// 		printf("MTN ICI\n");
// 		wait(NULL);
// 		printf("ET MTN ICI\n");
// 	}
// 	return (EXIT_FAILURE);
// }

int	main(void)
{
	int		pipefd[2];
	char	buf;

	printf("MAIN 1\n");
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(2);
	}
	pid_t	pid = fork();
	printf("MAIN 2\n");
	if (pid == -1)
	{
		perror("fork");
		exit(2);
	}
	else  if (pid == 0)
	{
		printf("PID == 0\n");
		// Enfant lit depuis le pipe
		close(pipefd[1]); // Ferme l'extremite inutilisee d'ecriture
		while (read(pipefd[0], &buf, 1) > 0)
		{
			write(1, &buf, 1);
		}
		write(1, "LA\n", 3);
		close(pipefd[0]);
		exit(2);
	}
	else
	{
		printf("ICI\n");
		// Parent : ecrit dans le pipe
		close(pipefd[0]); // Ferme l'extremite unitilisee d'ecriture
		write(pipefd[1], "Hello, child!", 13);
		close(pipefd[1]); // Signal EOF aux lecteurs du pipe
		printf("MTN ICI\n");
		wait(NULL);
		printf("ET MTN ICI\n");
	}
	return (0);
}