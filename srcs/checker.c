/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:58:19 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/26 17:14:40 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../Libraries/libft.h"

int	execute_inst(t_list **stack_a, t_list **stack_b, char *terminal)
{
	if (!ft_strcmp(terminal, "sa\n"))
		sa(stack_a, 0);
	else if (!ft_strcmp(terminal, "sb\n"))
		sb(stack_b, 0);
	else if (!ft_strcmp(terminal, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(terminal, "pa\n"))
		pa(stack_b, stack_a, 0);
	else if (!ft_strcmp(terminal, "pb\n"))
		pb(stack_a, stack_b, 0);
	else if (!ft_strcmp(terminal, "ra\n"))
		ra(stack_a, 0);
	else if (!ft_strcmp(terminal, "rb\n"))
		rb(stack_b, 0);
	else if (!ft_strcmp(terminal, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(terminal, "rra\n"))
		rra(stack_a, 0);
	else if (!ft_strcmp(terminal, "rrb\n"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(terminal, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		return (1);
	return (0);
}

int	already_sorted(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	is_sorted(t_list **stack_a)
{
	if (already_sorted(stack_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	free(stack_a);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*terminal;

	stack_a = malloc(sizeof(t_list *));
	stack_b = malloc(sizeof(t_list *));
	if (argc < 0 || !stack_a || !stack_b)
		return (ft_error_p(stack_a, stack_b, NULL), 0);
	*stack_a = NULL;
	*stack_b = NULL;
	check_args(argc, argv, stack_a, stack_b);
	init_list(argc, argv, stack_a);
	while (1)
	{
		terminal = get_next_line(0);
		if (!terminal)
			break ;
		if (execute_inst(stack_a, stack_b, terminal))
			ft_error_p(stack_a, stack_b, NULL);
		free(terminal);
	}
	is_sorted(stack_a);
	return (free_stacks(stack_a, stack_b), 0);
}
