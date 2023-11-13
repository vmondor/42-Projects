/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:52:15 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/13 16:31:19 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	s = str;
	return (s);
}

/*
int	main(void)
{
	char chaine[20] = "Hello, World!";
	char dest[20];
	char chainep[20] = "Hello, World!";

	memmove(chaine + 7, chaine + 12, 6);
	ft_memmove(chainep + 7, chainep + 12, 6);
	printf("Resultat ordi : %s\n", chaine);
	printf("Resultat perso : %s\n", chainep);
	return (0);
}
*/
