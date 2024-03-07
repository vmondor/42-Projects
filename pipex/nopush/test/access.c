/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:29:58 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/20 09:45:50 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	const char	*filename;

	filename = "file.txt";
	if (access(filename, F_OK) == -1)
		perror("Existe pas");
	if (access(filename, R_OK) == -1)
		perror("Peut pas etre lu");
	if (access(filename, W_OK) == -1)
		perror("Peut pas etre ecrit");
	if (access(filename, X_OK) == -1)
		perror("Peut pas etre executer");
	return (0);
}
