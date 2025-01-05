/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:32:41 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/05 19:35:36 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libraries/libft.h"

int	rotate(t_list **stack)
{
	t_list	*first_node;
	t_list	*current;
	int		j;

	if (ft_lstsize(*stack) <= 1)
		return (-1);
	first_node = *stack;
	*stack = first_node->next;
	first_node->next = NULL;
	ft_lstadd_back(stack, first_node);
	current = *stack;
	j = 1;
	while (current)
	{
		current->index = j++;
		current = current->next;
	}
	return (0);
}

int	ra(t_list **stack_a, int true)
{
	if (rotate(stack_a) == -1)
		return (-1);
	if (true == 1)
		write(1, "ra\n", 3);
	return (0);
}

int	rb(t_list **stack_b, int true)
{
	if (rotate(stack_b) == -1)
		return (-1);
	if (true == 1)
		write(1, "rb\n", 3);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if ((!ra(stack_a, 1)) || (!rb(stack_b, 1)))
		return (-1);
	ra(stack_a, 0);
	rb(stack_b, 0);
	return (0);
}
