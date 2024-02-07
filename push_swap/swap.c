/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:24:06 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/02 22:19:17 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(t_stack **stack_a, bool checker)
{
	swap(stack_a);
	if (!checker)
		ft_putstr("sa\n");
}

void	sb(t_stack **stack_b, bool checker)
{
	swap(stack_b);
	if (!checker)
		ft_putstr("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, bool checker)
{
	swap(stack_a);
	swap(stack_b);
	if (!checker)
		ft_putstr("ss\n");
}
