/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rev_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:34:58 by cmontaig          #+#    #+#             */
/*   Updated: 2025/02/18 00:56:26 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libraries/libft.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*last_node;
	t_list	*before_last;
	t_list	*current;

	if (ft_lstsize(*stack) <= 1)
		return (-1);
	last_node = *stack;
	before_last = NULL;
	while (last_node->next)
	{
		before_last = last_node;
		last_node = last_node->next;
	}
	before_last->next = NULL;
	ft_lstadd_front(stack, last_node);
	current = *stack;
	index_update(current);
	return (0);
}

int	rra(t_list **stack_a, int true)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	if (true == 1)
		write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_list **stack_b, int true)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	if (true == 1)
		write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((!rra(stack_a, 1)) || (!rrb(stack_b, 1)))
		return (-1);
	rra(stack_a, 0);
	rrb(stack_b, 0);
	write(1, "rrr\n", 4);
	return (0);
}
