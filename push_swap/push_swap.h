/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:41:21 by vmondor           #+#    #+#             */
/*   Updated: 2024/01/23 13:38:19 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h" //remove for push
# include <unistd.h> // read, write, exit
# include <stdlib.h> // malloc, free.
# include <stdio.h> // remove for push


typedef struct s_stack
{
	int				nb;
	struct s_list	*next;
}					t_stack;

typedef struct s_first_tack_a
{
	t_list	*first;
}			t_first_stack_a;

/* Verifier les input */

/* Allouer la stack */

/* Trier */

/* Mouvement */

void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack stack_b);

void	ft_pa(t_stack **stack_b, t_stack **stack_a);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);

void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);

void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

/* Stack_utils */

t_stack *ft_stacklast(t_stack *stack);
t_stack *ft_stack_beforelast(t_stack *stack);

/* Utils */
void    ft_putstr(char *str);

/* error */

#endif