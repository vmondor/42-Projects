/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:06:07 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/09 18:21:29 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	i = 0;
	while ((i < (size - 1)) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}
/*
#include <stdio.h>
int	main(void)
{
	char	dest[] = "srcDEST";
	char	src[] = "st";
	unsigned int	compt;

	compt = ft_strlcpy(dest, src, 5);
	printf("%d", compt);
	return (0);
}
*/
