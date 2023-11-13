/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:34:35 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/13 18:11:08 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	flag;

	i = 0;
	flag = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			flag = s1[i] - s2[i];
		i++;
	}
	if (i < n)
		flag = s1[i] - s2[i];
	return (flag);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	int	result;
	int	n;
	const char	s1[] = "Sadwedwedewme";
	const char	s2[] = "mize";
	char	sa[] = "Sadwedwedewme";
	char	sb[] = "mize";

	n = 4;
	printf("%d : %d\n", strncmp(s1, s2, n), ft_strncmp(sa, sb, n));
	return (0);
}
*/
