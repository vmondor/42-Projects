/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:47:33 by vmondor           #+#    #+#             */
/*   Updated: 2024/01/23 13:12:02 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_stacklast(t_stack *stack)
{
    if (stack == NULL)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

t_stack *ft_stack_beforelast(t_stack *stack)
{
    if (stack == NULL)
        return (NULL);
    while (stack && stack->next && stack->next->next != NULL)
        stack = stack->next;
    return (stack);
}