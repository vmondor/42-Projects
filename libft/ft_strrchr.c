/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:12:47 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/10 17:52:51 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	size_t	s_len;

	s_len = ft_strlen(s);
	while (s[s_len - 1])
	{
		if (s[s_len] == c)
			return ((char *)s + s_len);
		s_len--;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[20] = "Valentin-Vincent";
	char	str2[20] = "Valentin-Vincent";

	printf("%s : %s\n", strrchr(str, 'z'), ft_strrchr(str2, 'z'));
	return (0);
}
*/