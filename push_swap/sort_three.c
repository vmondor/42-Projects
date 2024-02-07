/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:43:00 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/06 15:57:04 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest_nb(t_stack *stack)
{
	int	nbr;

	nbr = stack->nb;
	while (stack)
	{
		if (stack->nb > nbr)
			nbr = stack->nb;
		stack = stack->next;
	}
	return (nbr);
}

void	sort_three(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_nb(*stack);
	if ((*stack)->nb == highest)
		ra(stack, false);
	else if ((*stack)->next->nb == highest)
		rra(stack, false);
	if ((*stack)->nb > (*stack)->next->nb)
		sa(stack, false);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(a, b, false);
	}
}
