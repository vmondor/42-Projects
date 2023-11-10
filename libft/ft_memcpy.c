/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:14:09 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/10 12:48:14 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_temp;
	const char	*src_temp;

	if (!dest && !src)
		return (0);
	dest_temp = dest;
	src_temp = src;
	i = 0;
	while (i <= n)
	{
		dest_temp[i] = src_temp[i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	char	src[10] = "SUCCESS";
	void	*dest = NULL;

	dest = ft_memcpy(dest, src, 10);
	printf("%s\n", (unsigned char*)dest);
	return (0);
}
*/