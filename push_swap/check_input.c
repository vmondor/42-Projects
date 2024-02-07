/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:13:28 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/07 20:29:14 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	if (!(*av) || !av[0])
		return (0);
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (j != i && ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

static long	arg_is_long(long nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		return (1);
	return (0);
}

int	is_correct_input(char **av, int i)
{
	int	nb;

	nb = 0;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		if (arg_is_long(ft_atol(av[i])))
			return (0);
		nb += arg_is_zero(av[i]);
		i++;
	}
	if (nb > 1)
		return (0);
	if (have_duplicates(av))
		return (0);
	return (1);
}
