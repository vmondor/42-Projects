/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:47:20 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/02 17:46:43 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *stack_cheapest)
{
	while (*a != stack_cheapest->target && *b != stack_cheapest)
		rr(a, b, false);
	set_index(*a);
	set_index(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *stack_cheapest)
{
	while (*a != stack_cheapest->target && *b != stack_cheapest)
		rrr(a, b, false);
	set_index(*a);
	set_index(*b);
}
