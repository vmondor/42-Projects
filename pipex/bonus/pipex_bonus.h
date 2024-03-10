/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:30:11 by vmondor           #+#    #+#             */
/*   Updated: 2024/03/07 19:58:20 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>	// exit
# include <stdio.h>		// perror
# include <unistd.h>	// close, access, dup, dup2, unlink, execve, fork, pipe
# include <fcntl.h>		// open
# include <errno.h>		// perror
# include <string.h>	// strerror
# include <sys/wait.h>	// for waitpid
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_data
{
	int		**pipefd;
	int		*pids;
	int		nbfork;
	int		fd_infile;
	int		fd_outfile;
	int		ac;
	char	**path;
	char	**cmds;
	char	**args;
	char	*command_to_execute;
}					t_data;

/* GET_NEXT_LINE */
char	*ft_strchr(char *s, int c);
char	*ft_strcpy(char *dest, char *src);
char	*get_next_line(int fd);

/* PARSING */
int		parsing(char **env, char *cmd);

/* INIT_VALUES */
void	init_pipe(t_data *data);
void	init_pids(t_data *data);
void	init_data(t_data *data, char **env, char *cmd);

/* GET_PATH */
char	**get_path(char **env);
void	get_command_path(t_data *data);

/* PIPEX */
void	pipex(int ac, char **av, char **env);

/* PIPEX_UTILS */
void	ft_dup2(int file_dest, int file_src);
void	check_access_file(char *infile, char *outfile);
int		open_infile(char *filename);
void	close_pipefd(t_data *data);
void	cleanup(t_data *data);

/* PROCESS */
void	process_child(t_data *data, char **env, char **av);

/* ERROR */
void	free_pipefd(t_data *data);
void	error_outfile(t_data *data);
void	error_pid(int *pipefd);
void	error(char *str);

/* HERE_DOC */
void	check_here_doc(int ac, char **av, char **env);

#endif