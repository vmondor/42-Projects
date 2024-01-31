/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:29:19 by vmondor           #+#    #+#             */
/*   Updated: 2024/01/31 15:21:52 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_to_b_until_three(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;

	size_a = ft_stack_size(*stack_a);
	while (size_a-- > 3)
		pb(stack_a, stack_b);
}

void	sort(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

	a_to_b_until_three(a, b);
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_index(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
