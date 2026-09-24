/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:30:06 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/26 14:53:54 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../Libraries/libft.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		check_args(argc, argv, stack_a, stack_b);
		stack_a = malloc(sizeof(t_list *));
		stack_b = malloc(sizeof(t_list *));
		if (!stack_a || !stack_b)
			return (ft_error_p(NULL, NULL, NULL), 1);
		*stack_a = NULL;
		*stack_b = NULL;
		init_list(argc, argv, stack_a);
		if (already_sorted(stack_a) == 1)
			return (free_stacks(stack_a, stack_b), 0);
		else if (argc == 4)
			algo_three(stack_a);
		else if (argc == 6)
			algo_five(stack_a, stack_b);
		else
			gen_algo(stack_a, stack_b);
	}
	return (free_stacks(stack_a, stack_b), 0);
}

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	free(stack_a);
	free(stack_b);
}

int	already_sorted(t_list **stack_a)
{
	t_list	*current;

	if (!stack_a || !(*stack_a))
		return (1);
	current = *stack_a;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
