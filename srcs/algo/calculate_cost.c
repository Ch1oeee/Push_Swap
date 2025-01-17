/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:09:56 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/17 15:33:42 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libraries/libft.h"

int calculate_individual_cost(int index, int size)
{
	if (index <= size / 2)
		return (index - 1);
	return (size - index + 1);
}

void calculate_move_cost(t_list **stack_a, t_list **stack_b)
{
	t_list *temp_b;
	int move_cost_b;
	int move_cost_a;
	int size_a;
	int size_b;
	
	temp_b = *stack_b;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	while (temp_b)
	{
		move_cost_b = calculate_individual_cost(temp_b->index, size_b);
		move_cost_a = calculate_individual_cost(temp_b->target_index, size_a);
		temp_b->cost = move_cost_a + move_cost_b + 1;
		temp_b = temp_b->next;
	}
	debug_stack(*stack_b, "B (After calculate_move_cost)");
}

t_list	*smallest_cost(t_list **stack_b)
{
	t_list	*temp;
	t_list	*smallest_cost;

	temp = (*stack_b);
	smallest_cost = temp;
	while (temp)
	{
		if (temp->cost < smallest_cost->cost)
			smallest_cost = temp;
		temp = temp->next;
	}
	return (smallest_cost);
}
