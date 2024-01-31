/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:41:21 by vmondor           #+#    #+#             */
/*   Updated: 2024/01/31 17:01:07 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // read, write, exit
# include <stdlib.h> // malloc, free.
# include <limits.h> // INT_MIN INT_MAX.
# include <stdbool.h> // bool
# include <stdio.h> // remove for push

typedef struct s_stack
{
	int				nb;
	int				index;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

/* Verifier les input */
char	**ft_split(char *str, char c);
int		is_digit(char c);
int		is_sign(char c);
int		ft_atoi(char *str);
long	ft_atol(char *str);
int		is_correct_input(char **av, int i);
int		ft_strcmp(const char *s1, const char *s2);

/* Allouer la stack */
t_stack	*stack_init_split(char **av);
t_stack	*stack_init(int ac, char **av);

/* Trier */
int		is_sorted(t_stack *stack);
void	sort_three(t_stack **stack);
void	sort(t_stack **stack_a, t_stack **stack_b);

/* Push_swap_init */
t_stack	*find_smallest(t_stack *stack);
void	set_target(t_stack *a, t_stack *b);
void	set_index(t_stack *stack);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);

/* Nodes */
void	init_nodes(t_stack *a, t_stack *b);
void	move_nodes(t_stack **a, t_stack **b);

/* Mouvement */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* Move utils both */
void	rotate_both(t_stack **a, t_stack **b, t_stack *stack_cheapest);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *stack_cheapest);

/* Stack_utils */
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stack_beforelast(t_stack *stack);
t_stack	*ft_stack_new(int nb);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
int		ft_stack_size(t_stack *stack);

/* Utils */
void	ft_putstr(char *str);
void	free_stack(t_stack **stack);
int		nb_abs(int nb);

/* Algorythm */
void	set_target(t_stack *a, t_stack *b);

/* error */
void	ft_error(t_stack **stack_a, t_stack **stack_b);

#endif