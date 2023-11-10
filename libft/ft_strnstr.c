/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:48:31 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/10 18:05:24 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*flag;

	i = 0;
	flag = (char *)big;
	n_len = ft_strlen(little);
	if (n_len == 0 || big == little)
		return (flag);
	while (flag[i] != '\0' && i < len)
	{
		c = 0;
		while (flag[i + c] != '\0' && little[c] != '\0'
			&& flag[i + c] == little[c] && i + c < len)
			c++;
		if (c == n_len)
			return (flag + i);
		i++;
	}
	return (0);
}
