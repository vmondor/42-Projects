/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:24:06 by vmondor           #+#    #+#             */
/*   Updated: 2024/02/07 21:22:58 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_sorted_checker(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	ft_strncmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

static void	check_command(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strncmp(command, "pa\n"))
		pa(a, b, true);
	else if (!ft_strncmp(command, "pb\n"))
		pb(a, b, true);
	else if (!ft_strncmp(command, "sa\n"))
		sa(a, true);
	else if (!ft_strncmp(command, "sb\n"))
		sb(b, true);
	else if (!ft_strncmp(command, "ss\n"))
		ss(a, b, true);
	else if (!ft_strncmp(command, "ra\n"))
		ra(a, true);
	else if (!ft_strncmp(command, "rb\n"))
		rb(b, true);
	else if (!ft_strncmp(command, "rr\n"))
		rr(a, b, true);
	else if (!ft_strncmp(command, "rra\n"))
		rra(a, true);
	else if (!ft_strncmp(command, "rrb\n"))
		rrb(b, true);
	else if (!ft_strncmp(command, "rrr\n"))
		rrr(a, b, true);
	else
		ft_error(a, b);
}

static void	check(int ac, char **av, t_stack **a)
{
	char	**tab;

	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!tab)
			return ;
		if (!is_correct_input(tab, 0))
		{
			free_tab(tab);
			free(tab);
			ft_error(NULL, NULL);
		}
		*a = stack_init_split(tab);
	}
	else
	{
		if (!is_correct_input(av, 1))
			ft_error(NULL, NULL);
		*a = stack_init(ac, av);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		len;

	if (ac == 1)
		return (0);
	a = NULL;
	b = NULL;
	check(ac, av, &a);
	len = ft_stack_size(a);
	line = get_next_line(0);
	while (line)
	{
		check_command(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted_checker(a) && ft_stack_size(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
