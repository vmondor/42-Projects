/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:26:37 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/18 14:35:48 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_lenght(int n)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		count++;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	nbr;
	int		lenght;

	nbr = nb;
	lenght = ft_lenght(nbr);
	str = malloc(sizeof(char) * lenght + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	str[lenght] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[--lenght] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}
