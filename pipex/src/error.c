/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:02:16 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/21 13:22:29 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str)
{
	if (!str)
		str = " ";
	ft_printf("Error\n");
	write(2, str, ft_strlen(str));
	exit (EXIT_FAILURE);
}
