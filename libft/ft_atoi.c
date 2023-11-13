/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:00:51 by vmondor           #+#    #+#             */
/*   Updated: 2023/11/13 18:10:25 by vmondor          ###   ########.fr       */
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
	if (!nptr)
		return (0);
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		negative = -1;
	else
		negative = 1;
	if (negative == -1 || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - 48);
		i++;
	}
	number = number * negative;
	return (number);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	str[] = "+-54";
	printf("%d : %d\n", atoi(str), ft_atoi(str));
}
*/
