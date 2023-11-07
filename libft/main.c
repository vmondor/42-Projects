/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:00:10 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/07 14:49:48 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);

int	main(void)
{
	char	str[10] = "Bonj";

	printf("%zu\n", ft_strlen(str));
	return (0);
}
