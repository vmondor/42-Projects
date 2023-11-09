/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:14:09 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/09 16:05:59 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*desttemp;
	const char	*srctemp;

	if (!dest && !src)
		return (0);
	desttemp = dest;
	srctemp = src;
	i = 0;
	while (i <= n)
	{
		desttemp[i] = srctemp[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char source[] = "Hello World";
	char source2[] = "Hello World !";
	char destination[20];
	char destination2[20];

	memcpy(destination, source, sizeof(source));
	ft_memcpy(destination2, source2, sizeof(source));
	printf("Resultat ordi\t: %s : %s\n", source, destination);
	printf("Resultat perso\t: %s : %s\n", source2, destination2);
	return (0);
}
*/
