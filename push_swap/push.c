/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:35:00 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/02 17:49:07 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*temp;

	if (*stack_src == NULL)
		return ;
	temp = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = temp;
}

void	pa(t_stack **stack_a, t_stack **stack_b, bool checker)
{
	push(stack_b, stack_a);
	if (!checker)
		ft_putstr("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, bool checker)
{
	push(stack_a, stack_b);
	if (!checker)
		ft_putstr("pb\n");
}
