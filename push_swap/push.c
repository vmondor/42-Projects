/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:35:00 by vmondor           #+#    #+#             */
/*   Updated: 2024/01/23 13:32:18 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*temp;

	if (*stack_src == NULL)
		return ;
	temp = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = temp;
}

void	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putstr("pb\n");
}
