/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:53:10 by cmontaig          #+#    #+#             */
/*   Updated: 2025/02/17 19:47:24 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libraries/libft.h"

void	find_closest_values(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	t_list	*temp_a;

	temp_b = *stack_b;
	while (temp_b)
	{
		temp_a = *stack_a;
		temp_b->target_value = INT_MAX;
		while (temp_a)
		{
			if (temp_a->content > temp_b->content && temp_a->content
				< temp_b->target_value)
			{
				temp_b->target_value = temp_a->content;
				temp_b->target_index = temp_a->index;
			}
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}

void	closest_value_a(t_list **stack_a, t_list **stack_b)
{
	find_closest_values(stack_a, stack_b);
	calculate_move_cost(stack_a, stack_b);
}

void	gen_rotate(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest_cost_node;

	smallest_cost_node = smallest_cost(stack_b);
	while (smallest_cost_node->index != 1)
	{
		if (smallest_cost_node->index <= (ft_lstsize(*stack_b) / 2))
			rb(stack_b, 1);
		else
			rrb(stack_b, 1);
		smallest_cost_node = smallest_cost(stack_b);
	}
	while (smallest_cost_node->target_index != 1)
	{
		if (smallest_cost_node->target_index <= (ft_lstsize(*stack_a) / 2))
		{
			ra(stack_a, 1);
			update_target_index_ra(smallest_cost_node, *stack_a);
		}
		else
		{
			rra(stack_a, 1);
			update_target_index_rra(smallest_cost_node, *stack_a);
		}
	}
	pa(stack_a, stack_b, 1);
}

void	final_rotate(t_list **stack_a)
{
	t_list	*smallest;

	smallest = find_smallest(*stack_a);
	while (smallest->index != 1)
	{
		if (smallest->index < (ft_lstsize(*stack_a) / 2))
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

void	gen_algo(t_list **stack_a, t_list **stack_b)
{
	med_supp(stack_a, stack_b);
	algo_three(stack_a);
	while (*stack_b != NULL)
	{
		closest_value_a(stack_a, stack_b);
		gen_rotate(stack_a, stack_b);
	}
	final_rotate(stack_a);
}
