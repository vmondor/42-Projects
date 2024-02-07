/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:06:20 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/07 14:50:10 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*before_last;

	if (*stack == NULL)
		return ;
	last = ft_stacklast(*stack);
	before_last = ft_stack_beforelast(*stack);
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	before_last->next = NULL;
}

void	rra(t_stack **stack_a, bool checker)
{
	reverse_rotate(stack_a);
	if (!checker)
		ft_putstr("rra\n");
}

void	rrb(t_stack **stack_b, bool checker)
{
	reverse_rotate(stack_b);
	if (!checker)
		ft_putstr("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool checker)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (!checker)
		ft_putstr("rrr\n");
}
