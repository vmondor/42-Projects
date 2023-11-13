/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:43:41 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/13 19:04:27 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	i;
	char	*str;

	s = (void *)malloc(nmemb * size);
	if (!s)
		return (NULL);
	i = 0;
	str = s;
	while (i < nmemb)
	{
		str[i] = 0;
		i++;
	}
	s = str;
	return (s);
}
