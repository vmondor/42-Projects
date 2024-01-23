/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:06:20 by vmondor           #+#    #+#             */
/*   Updated: 2024/01/23 13:21:11 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*before_last;

	last = ft_stacklast(*stack);
	before_last = ft_stack_beforelast(*stack);
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	before_last->next = NULL;
}

void	ft_rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_putstr("rra\n");
}