/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:54:07 by vmondor           #+#    #+#             */
/*   Updated: 2024/01/23 13:22:11 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	last = ft_stacklast(*stack);
	temp = stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	last->next = temp;
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_putstr("ra\n");
}