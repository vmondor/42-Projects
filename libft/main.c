/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:38:03 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/09 16:39:09 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void	*ft_memmove(void *dest, const void *src, size_t n);

int	main(void)
{
	char chaine[20] = "Hello, World!";
//	char dest[20];
//	char chainep[20] = "Hello, World!";

	memmove(chaine + 7, chaine + 12, 6);
//	ft_memmove(chainep + 7, chainep + 12, 6);
	printf("Resultat ordi : %s\n", chaine);
//	printf("Resultat perso : %s\n", chainep);
	return (0);
}
