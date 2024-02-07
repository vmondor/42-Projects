/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:54:07 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/07 14:49:48 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack == NULL)
		return ;
	last = ft_stacklast(*stack);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	last->next = temp;
}

void	ra(t_stack **stack_a, bool checker)
{
	rotate(stack_a);
	if (!checker)
		ft_putstr("ra\n");
}

void	rb(t_stack **stack_b, bool checker)
{
	rotate(stack_b);
	if (!checker)
		ft_putstr("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, bool checker)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!checker)
		ft_putstr("rr\n");
}
