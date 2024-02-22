/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:30:11 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 19:20:12 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>	// exit
# include <stdio.h>		// printf, perror
# include <unistd.h>	// close, access, dup, dup2, unlink, execve, fork, pipe
# include <fcntl.h>		// open
# include <errno.h>		// perror
# include <string.h>	// strerror
# include <sys/wait.h>	// for waitpid
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

/* PARSING */
void	parsing(int ac, char **av);

/* GET_PATH */
char	**get_path(char **env);

/* PIPEX */
void	pipex(char **av, char **env, char **cmd1);

/* ERROR */
void	error(char *str);

#endif