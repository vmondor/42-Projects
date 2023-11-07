/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:00:10 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/07 18:01:26 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n);

int	main(void)
{
	void	*test;
	void	*true;
	char	*restest;
	char	*restrue;
	char	*tab[5];

	test = ft_memset(tab, '1', 5);
	true = memset(tab, '1', 5);
	restest = test;
	restrue = true;
	printf("%s : %s", restest, restrue);
}
