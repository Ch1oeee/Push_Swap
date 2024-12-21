/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:38:04 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/14 14:27:17 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_2;
	t_list	*lst_temp;

	if (!lst || !del)
		return ;
	lst_2 = *lst;
	while (lst_2 != NULL)
	{
		lst_temp = lst_2;
		lst_2 = lst_2->next;
		del(lst_temp->content);
		free(lst_temp);
	}
	*lst = NULL;
}
