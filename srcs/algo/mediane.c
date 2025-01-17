/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:22:10 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/17 16:39:09 by cmontaig         ###   ########.fr       */
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
			break ;
		i++;
	}
}

void	med_supp(t_list **stack_a, t_list **stack_b)
{
	int	mediane;
	int size;
	t_list *temp;
	
	temp = *stack_a;
	while ((size = ft_lstsize(*stack_a)) > 3)
	{
		mediane = get_mediane(stack_a);
		while (temp && ft_lstsize(*stack_a) > 3)
		{
			if ((*stack_a)->content < mediane)
				pb(stack_a, stack_b);
			else
			{
				ra(stack_a, 1);
			}
			temp = *stack_a;
		}
	}
}
