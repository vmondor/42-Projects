/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:02:16 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/19 12:35:29 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error(char *str, char **tab)
{
	if (!str)
		str = " ";
	ft_printf("Error\n%s\n", str);
	if (tab)
		free_tab(tab);
	exit (1);
}
