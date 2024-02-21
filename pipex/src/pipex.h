/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:30:11 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 14:44:02 by vmondor          ###   ########.fr       */
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
# include <sys/types.h>	// for waitpid remove for push
# include <sys/wait.h>	// for waitpid remove for push
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"


/* PARSING */
void	parsing(int ac, char **av, char **env);

/* GET_PATH */
void	get_path(char **env);

/* ERROR */
void	error(char *str);


#endif