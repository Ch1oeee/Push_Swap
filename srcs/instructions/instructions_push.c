/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:36:43 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/24 16:15:26 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libraries/libft.h"

int	pb(t_list **stack_a, t_list **stack_b, int true)
{
	t_list	*first_node;
	t_list	*current;

	if (ft_lstsize(*stack_a) < 1)
		return (-1);
	first_node = *stack_a;
	*stack_a = first_node->next;
	first_node->next = NULL;
	ft_lstadd_front(stack_b, first_node);
	current = *stack_b;
	index_update(current);
	current = *stack_a;
	index_update(current);
	if (true == 1)
		write(1, "pb\n", 3);
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b, int true)
{
	t_list	*first_node;
	t_list	*current;

	if (ft_lstsize(*stack_b) < 1)
		return (-1);
	first_node = *stack_b;
	*stack_b = first_node->next;
	first_node->next = NULL;
	ft_lstadd_front(stack_a, first_node);
	current = *stack_a;
	index_update(current);
	current = *stack_b;
	index_update(current);
	if (true == 1)
		write(1, "pa\n", 3);
	return (0);
}

void	index_update(t_list *current)
{
	int	j;

	j = 1;
	while (current)
	{
		current->index = j++;
		current = current->next;
	}
}
