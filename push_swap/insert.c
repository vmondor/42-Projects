/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:18:20 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/03 14:17:57 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init_split(char **av)
{
	t_stack		*stack_a;
	long		nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		free(av[i]);
		if (i == 0)
			stack_a = ft_stack_new((int)nb);
		else
			ft_stackadd_back(&stack_a, ft_stack_new((int)nb));
		i++;
	}
	free(av);
	return (stack_a);
}

t_stack	*stack_init(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (i == 1)
			stack_a = ft_stack_new((int)nb);
		else
			ft_stackadd_back(&stack_a, ft_stack_new((int)nb));
		i++;
	}
	return (stack_a);
}
