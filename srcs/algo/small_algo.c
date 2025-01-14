/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:00:42 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/10 15:15:23 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libraries/libft.h"

t_list	*find_biggest(t_list *stack)
{
	t_list	*biggest;

	biggest = stack;
	while (stack)
	{
		if (stack->content > biggest->content)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_list	*find_smallest(t_list *stack)
{
	t_list	*smallest;

	smallest = stack;
	while (stack)
	{
		if (stack->content < smallest->content)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

int	algo_three(t_list **stack_a)
{
	t_list	*biggest;

	biggest = find_biggest(*stack_a);
	if ((*stack_a) == biggest)
		ra(stack_a, 1);
	else if (biggest == (*stack_a)->next)
		rra(stack_a, 1);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a, 1);
	return (0);
}

int	algo_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest;

	while (ft_lstsize(*stack_a) > 3)
	{
		smallest = find_smallest(*stack_a);
		if (smallest->index <= (ft_lstsize(*stack_a) / 2))
		{
			while (*stack_a != smallest)
				ra(stack_a, 1);
		}
		else
		{
			while (*stack_a != smallest)
				rra(stack_a, 1);
		}
		pb(stack_a, stack_b);
	}
	algo_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (0);
}
