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

	if (!s)
		return (NULL);
	str = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	char s[] = {0, 1, 2, 3, 4, 5};
	char *res;
	char *res2;

	res = (char *)ft_memchr(s, 2 + 256, 3) == s + 2;
	res2 = (char *)memchr(s, 2 + 256, 3) == s + 2;
	printf("%s : %s\n", res, res2);
	return (0);
}
*/
