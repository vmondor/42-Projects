/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:28:11 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/09 18:29:17 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	if (src[0] == '\0')
		return (0);
	while (src[i] && (destlen + i < (size - 1)))
	{
		dest[destlen + i] = src[i];
		i++;
	}
	if (i < size)
		dest[destlen + i] = '\0';
	if (destlen > size)
		return (srclen + size);
	return (destlen + srclen);
}

#include <stdio.h>

int	main(void)
{
	unsigned int	size;
	unsigned int	i;
	char	dest[12] = "Bonjour ";
	char	src[] = "tout";

	size = 12;
	i = 0;
		//ft_strlcat(dest, src, size);
	while(dest[i])
	{
		printf("%c", dest[i]);
		i++;
	}
		printf("\n");
	printf("%d\n", ft_strlcat(dest, src, size));
	return (0);
}
