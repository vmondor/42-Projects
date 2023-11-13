/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:27:53 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/13 19:05:22 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	ft_strcpy(str, s);
	return (str);
}
/*
int	main(void)
{
	printf("Ordi\t: %s\n", strdup("Ecole 42"));
	printf("Moi\t: %s\n", ft_strdup("Ecole 42"));
	return (0);
}
*/
