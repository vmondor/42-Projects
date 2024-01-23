/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:24:06 by vmondor           #+#    #+#             */
/*   Updated: 2024/01/23 12:34:27 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = temp;
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(*stack_a);
	ft_putstr("sa\n");
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(*stack_b);
	ft_putstr("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(*stack_a);
	ft_swap(*stack_b);
	ft_putstr("ss\n");
}
