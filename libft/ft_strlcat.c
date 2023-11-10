/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:24:11 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/10 17:50:26 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	if (src[0] == '\0')
		return (0);
	while (src[i] && (destlen + i < (size - 1)))
	{
		dst[destlen + i] = src[i];
		i++;
	}
	if (i < size)
		dst[destlen + i] = '\0';
	if (destlen > size)
		return (srclen + size);
	return (destlen + srclen);
}

/*
#include <bsd/string.h>

int	main(void)
{
	size_t	size;
	size_t	i;
	char	dest[20] = "Bonjour ";
	char	dest2[20] = "Bonjour ";
	char	src[] = "tout";
	char	src2[] = "tout";

	size = 20;
	i = 0;
	while(dest[i])
	{
		printf("%c : %c\n", dest[i], dest2[i]);
		i++;
	}
	printf("\n");
	printf("%zu : %zu\n", strlcat(dest, src, size), ft_strlcat(dest2, src2, size));
	return (0);
}
*/