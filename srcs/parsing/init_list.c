/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:58:55 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/16 21:35:18 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libraries/libft.h"

void	check_args(int argc, char **argv)
{
	int		i;
	char	**split_args;

	i = 1;
	if (argc > 2)
	{
		if (limits(argv + 1) == 1)
			ft_error_p();
		if (duplicate(argv + 1) == 1)
			ft_error_p();
	}
	else if (argc == 2)
	{
		split_args = ft_split(argv[1], "	 ");
		if(!split_args)
			ft_error_p();
		i = 0;
		while (split_args[i++])
		{
			if (limits(split_args + i) == 1)
				ft_error_p();
			if (duplicate(split_args + i) == 1)
				ft_error_p();
		}
	}
}

void	init_list_split(char **split_args, t_list **stack)
{
	t_list	*new;
	int		i;
	int		index;

	index = 1;
	i = 0;
	*stack = NULL;
	while (split_args[i])
	{
		new = ft_lstnew(ft_atoi_swap(split_args[i]));
		new->index = index;
		ft_lstadd_back(stack, new);
		i++;
		index++;
	}
}

void	init_list(int argc, char **argv, t_list **stack)
{
	t_list	*new;
	int		i;
	int		index;
	int		j;
	
	index = 1;
	i = 1;
	j = 0;
	*stack = NULL;
	if (argc > 2)
	{
		while(argv[i])
		{
			new = ft_lstnew(ft_atoi_swap(argv[i]));
			new->index = index;
			ft_lstadd_back(stack, new);
			i++;
			index++;
		}
	}
	else if (argc == 2)
	{
		char **split_args = ft_split(argv[1], "	 ");
		if (!split_args)
			ft_error_p();
		init_list_split(split_args, stack);
		while (split_args[j])
			free(split_args[j++]);
		free(split_args);
	}
}