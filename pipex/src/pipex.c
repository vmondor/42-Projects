/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:54:00 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 12:31:23 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    execute_cmd(char *cmd, int in_fd, int out_fd)
{
    pid_t   pid;
    int     status;

    pid = fork();
    if (pid == 0)
    {
        if (in_fd != STDIN_FILENO)
        {
            dup2(in_fd, STDIN_FILENO);
            close(in_fd);
        }
        if (out_fd != STDOUT_FILENO)
        {
            dup2(out_fd, STDOUT_FILENO);
            close(out_fd);
        }
        execlp(cmd, cmd, NULL);
        perror("execlp");
        exit(2);
    }
    else if (pid < 0)
    {
        perror("fork");
        exit(2);
    }
    else
        waitpid(pid, &status, 0);
}

int	main(int ac, char **av)
{
	(void)ac;

	ft_printf("***** PIPEX *****\n\n");

	//	cat prenom.txt | wc -l > file2.txt
	//	./pipex prenom.txt "cat" "wc -l" file2.txt

    int *fd;
    int file_in;
    int file_out;

    if (ac != 5)
    {
        ft_printf("Il doit y avoir 4 argument : file1 cmd1 cmd2 file2\n");
        return (1);
    }
    if (!(fd = malloc(sizeof(int) * 2)))
        return (1);
    file_in = open(av[1], O_RDONLY);
    file_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (file_in < 0 || file_out < 0)
    {
        perror("open");
        return (1);
    }

    if (pipe(fd) == -1)
    {
        perror("pipe");
        return (1);
    }
    execute_cmd(av[2], fd[1], file_in);
    close(fd[1]);

    execute_cmd(av[3], fd[0], file_out);
    close(fd[0]);
    return (0);
}