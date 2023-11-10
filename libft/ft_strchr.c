/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:13:02 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/10 17:14:12 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[20] = "Valentin";
	char	str2[20] = "Valentin";

	printf("%s : %s\n", strchr(str, 'i'), ft_strchr(str2, 'i'));
	return (0);
}
*/