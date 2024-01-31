/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:05:43 by vmondor           #+#    #+#             */
/*   Updated: 2024/01/31 16:07:41 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*stack_current;

	stack_current = stack;
	while (stack)
	{
		if (stack->nb < stack_current->nb)
			stack_current = stack;
		stack = stack->next;
	}
	return (stack_current);
}

void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nb > b->nb && current_a->nb < best_match_index)
			{
				best_match_index = current_a->nb;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->cheapest = false;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_stack_size(a);
	size_b = ft_stack_size(b);
	while (b)
	{
		b->push_price = b->index;
		if (!(b->above_median))
			b->push_price = size_b - (b->index);
		if (b->target->above_median)
			b->push_price += b->target->index;
		else
			b->push_price += size_a - (b->target->index);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long	min_price;
	t_stack	*stack_min_price;

	if (!b)
		return ;
	min_price = LONG_MAX;
	while (b)
	{
		if (b->push_price < min_price)
		{
			min_price = b->push_price;
			stack_min_price = b;
		}
		b = b->next;
	}
	stack_min_price->cheapest = true;
}
