/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:53:10 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/14 17:44:19 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libraries/libft.h"

int	get_mediane(t_list **stack_a)
{
	t_list	*temp;
	int		*list_element;
	int		i;
	int		size;
	int		mediane;

	i = 0;
	temp = *stack_a;
	size = ft_lstsize(*stack_a);
	list_element = malloc(size * sizeof(int));
	if (!list_element)
		return (0);
	while (temp)
	{
		list_element[i] = temp->content;
		i++;
		temp = temp->next;
	}
	sort_list(list_element, size);
	mediane = list_element[size / 2];
	free(list_element);
	return (mediane);
}

void	sort_list(int *list_element, int size)
{
	int	temp;
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < size - 1) 
	{
		swapped = 0;
		j = 0;
		while (j < size - 1 - i)
		{
			if (list_element[j] > list_element[j + 1])
			{
				temp = list_element[j];
				list_element[j] = list_element[j + 1];
				list_element[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0) 
			break;
		i++;
	}
}

int	med_supp(t_list **stack_a, t_list **stack_b)
{
	int	mediane;
	int size;

	while ((size = ft_lstsize(*stack_a)) > 3)
	{
		mediane = get_mediane(stack_a);
			if ((*stack_a)->content < mediane)
				pb(stack_a, stack_b);
			else
				ra(stack_a, 1);
	}
	return (0);
}

int	closest_value_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	
	temp_b = *stack_b;
	while (temp_b)
	{
		temp_a = *stack_a;
		temp_b->target_value = INT_MAX;
		while (temp_a)
		{
			if (temp_a->content > temp_b->content)
			{
  				{
					temp_b->target_value = temp_a->content;
					temp_b->target_index = temp_a->index;
				}
			}
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
	
	return (0);
}

void	gen_algo(t_list **stack_a, t_list **stack_b)
{

	med_supp(stack_a, stack_b);
	algo_three(stack_a);
	while (1)
	{
		closest_value_a(stack_a, stack_b);
		calculate_move_cost(stack_a, stack_b);
	}
}

int	calculate_move_cost(t_list **stack_a, t_list **stack_b)
{
	int	moves;


	moves = 0;
}
