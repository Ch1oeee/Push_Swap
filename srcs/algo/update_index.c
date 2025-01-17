/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:23:32 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/17 15:18:56 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libraries/libft.h"


void	update_smallest_index_rb(t_list *smallest_cost_node, t_list *stack_b)
{
	int size = ft_lstsize(stack_b);

	if (smallest_cost_node->index > 1)
		smallest_cost_node->index--;
	else
		smallest_cost_node->index = size;
}

void	update_smallest_index_rrb(t_list *smallest_cost_node, t_list *stack_b)
{
	int size = ft_lstsize(stack_b);

	if (smallest_cost_node->index < size)
		smallest_cost_node->index++;
	else
		smallest_cost_node->index = 1;
}

void	update_target_index_ra(t_list *smallest_cost_node, t_list *stack_a)
{
	int size = ft_lstsize(stack_a);

	if (smallest_cost_node->target_index > 1)
		smallest_cost_node->target_index--;
	else
		smallest_cost_node->target_index = size;
}

void	update_target_index_rra(t_list *smallest_cost_node, t_list *stack_a)
{
	int size = ft_lstsize(stack_a);

	if (smallest_cost_node->target_index < size)
		smallest_cost_node->target_index++;
	else
		smallest_cost_node->target_index = 1;
}
