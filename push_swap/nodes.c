/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:09:45 by vmondor           #+#    #+#             */
/*   Updated: 2024/01/31 17:01:42 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*return_cheapest(t_stack *stack)
{
	t_stack	*cheapest;

	cheapest = NULL;
	while (stack)
	{
		if (stack->cheapest)
		{
			cheapest = stack;
			break ;
		}
		stack = stack->next;
	}
	return (cheapest);
}

static void	finish_rotation(t_stack **stack, t_stack *head, char stack_name)
{
	while (*stack != head)
	{
		if (stack_name == 'a')
		{
			if (head->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (head->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*stack_cheapest;

	stack_cheapest = return_cheapest(*b);
	if (stack_cheapest->above_median && stack_cheapest->target->above_median)
		rotate_both(a, b, stack_cheapest);
	else if (!(stack_cheapest->above_median)
		&& !(stack_cheapest->target->above_median))
		reverse_rotate_both(a, b, stack_cheapest);
	finish_rotation(b, stack_cheapest, 'b');
	finish_rotation(a, stack_cheapest->target, 'a');
	pa(a, b);
}
