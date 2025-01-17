/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:54:52 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/17 11:52:33 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"
#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_el;

	new_el = malloc(sizeof(t_list));
	if (!new_el)
		return (NULL);
	new_el->content = content;
	new_el->target_value = INT_MAX;
	new_el->index = 0;
	new_el->target_index = 0;
	new_el->cost = INT_MAX;
	new_el->next = NULL;
	return (new_el);
}
