/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:29:19 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/06 15:49:13 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	get_average(t_stack *stack)
{
	long	average;
	int		stacklen;

	if (!stack)
		return (0);
	average = 0;
	stacklen = ft_stack_size(stack);
	while (stack)
	{
		average += (long)stack->nb;
		stack = stack->next;
	}
	average = average / (long)stacklen;
	return (average);
}

static void	set_above_average(t_stack **stack)
{
	long	average;

	average = get_average(*stack);
	while (*stack)
	{
		if ((long)(*stack)->nb > average)
			(*stack)->above_average = true;
		else
			(*stack)->above_average = false;
		*stack = (*stack)->next;
	}
}

static void	push_to_b_until_three(t_stack **a, t_stack **b)
{
	int		a_len;
	int		size;
	int		i;
	t_stack	*temp;

	temp = *a;
	i = 0;
	set_above_average(a);
	*a = temp;
	a_len = ft_stack_size(*a);
	size = a_len;
	while (i < size && a_len > 3)
	{
		if ((*a)->above_average == false)
		{
			pb(a, b, false);
			a_len--;
		}
		else
			ra(a, false);
		i++;
	}
	a_len = ft_stack_size(*a);
	while (a_len-- > 3)
		pb(a, b, false);
}

void	sort(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		a_len;

	a_len = ft_stack_size(*a);
	if (a_len == 5)
		sort_five(a, b);
	else
		push_to_b_until_three(a, b);
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
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
