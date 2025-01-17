/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:53:10 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/17 16:38:46 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libraries/libft.h"

void find_closest_values(t_list **stack_a, t_list **stack_b)
{
	t_list *temp_b = *stack_b;
	t_list *temp_a = *stack_a;

	while (temp_b)
	{
		temp_b->target_value = INT_MAX;
		while (temp_a)
		{
			if (temp_a->content > temp_b->content && temp_a->content < temp_b->target_value)
			{
				temp_b->target_value = temp_a->content;
				temp_b->target_index = temp_a->index;
			}
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}

void closest_value_a(t_list **stack_a, t_list **stack_b)
{
	find_closest_values(stack_a, stack_b);
	calculate_move_cost(stack_a, stack_b);
}

void	gen_rotate(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest_cost_node;

	smallest_cost_node = smallest_cost(stack_b);
	printf("smallest cost node %d\n", smallest_cost_node->content);
	while (smallest_cost_node->index != 1)
	{
		if (smallest_cost_node->index < (ft_lstsize(*stack_b) / 2))
		{
			rb(stack_b, 1);
			update_smallest_index_rb(smallest_cost_node, *stack_b);
		}
		else
		{
			rrb(stack_b, 1);
			update_smallest_index_rrb(smallest_cost_node, *stack_b);
		}
		// smallest_cost_node = smallest_cost(stack_b);
	}
	while (smallest_cost_node->target_index != 1)
	{
		if (smallest_cost_node->target_index < (ft_lstsize(*stack_a) / 2))
		{
			ra(stack_a, 1);
			update_target_index_ra(smallest_cost_node, *stack_a);
		}
		else
		{
			rra(stack_a, 1);
			update_target_index_rra(smallest_cost_node, *stack_a);
		}
		// smallest_cost_node = smallest_cost(stack_b);
	}
	pa(stack_a, stack_b);
}

void	gen_algo(t_list **stack_a, t_list **stack_b)
{
	med_supp(stack_a, stack_b); //banger
	algo_three(stack_a); //banger
	while (*stack_b != NULL)
	{
		closest_value_a(stack_a, stack_b); //ca a l'air banger
		gen_rotate(stack_a, stack_b);
		
		debug_stack(*stack_a, "A (After gen_rotate)");
		debug_stack(*stack_b, "B (After gen_rotate)");
	}
	debug_stack(*stack_a, "A (Final)");
}

void debug_stack(t_list *stack, const char *stack_name)
{
	printf("Stack %s:\n", stack_name);
	while (stack)
	{
		printf("Content: %d, Index: %d, Target_value: %d, Target_index: %d, Cost: %d\n",
			stack->content, stack->index, stack->target_value,
			stack->target_index, stack->cost);
		stack = stack->next;
	}
	printf("\n");
}
