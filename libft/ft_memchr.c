/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:46:54 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/10 17:56:57 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;

	str = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	str[20] = " Valentin Mondor";
	void	*result;
	void	*result2;
	
	result = memchr(str, (int)'M', 20);
	result2 = ft_memchr(str, (int)'M', 20);
	printf("%s : %s\n", (char *)result, (char *)result2);
	return (0);
}
*/