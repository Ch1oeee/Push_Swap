/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:07:20 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/05 19:27:37 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libraries/libft.h"

int	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	int		temp_content;
	int		temp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	first = *stack;
	second = first->next;
	temp_content = second->content;
	temp_index = second->index;
	second->content = first->content;
	second->index = first->index;
	first->content = temp_content;
	first->index = temp_index;
	return (0);
}

int	sa(t_list **stack_a, int true)
{
	if (swap(stack_a) == -1)
		return (-1);
	if (true == 1)
		write(1, "sa\n", 3);
	return (0);
}

int	sb(t_list **stack_b, int true)
{
	if (swap(stack_b) == -1)
		return (-1);
	if (true == 1)
		write(1, "sb\n", 3);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if ((!sa(stack_a, 1)) || (!sb(stack_b, 1)))
		return (-1);
	sa(stack_a, 0);
	sb(stack_b, 0);
	return (0);
}
