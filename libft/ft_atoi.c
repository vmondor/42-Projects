/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:00:51 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/10 18:08:18 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	number;
	int	i;
	int	negative;

	number = 0;
	i = 0;
	negative = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negative++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - 48);
		i++;
	}
	if (negative % 2 != 0)
		number = number * -1;
	return (number);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = " ---+--+1234ab567";
	printf("%d\n", ft_atoi(str));
}
*/
