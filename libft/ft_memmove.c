/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:08:28 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/09 18:04:50 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_temp;
	unsigned char	*src_temp;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		dest_temp = (unsigned char *)dest;
		src_temp = (unsigned char *)src;
		while (n--)
			*dest_temp++ = *src_temp++;
	}
	else
	{
		dest_temp = (unsigned char *)dest + (n - 1);
		src_temp = (unsigned char *)src + (n - 1);
		while (n--)
			*dest_temp-- = *src_temp--;
	}
	return (dest);
}
/*
int	main(void)
{
	char chaine[20] = "Valentin-Mondor";
	char chainep[20] = "Valentin-Mondor";

	memmove(chaine + 7, chaine + 12, 6);
	ft_memmove(chainep + 7, chainep + 12, 6);
	printf("Resultat ordi : %s\n", chaine);
	printf("Resultat perso : %s\n", chainep);
	return (0);
}
*/
