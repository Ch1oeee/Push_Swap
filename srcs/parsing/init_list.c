/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:58:55 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/26 15:26:07 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libraries/libft.h"

void	check_args(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
	char	**split_args;

	split_args = NULL;
	if (argc > 2)
	{
		if (limits(argv + 1) == 1)
			ft_error_p(stack_a, stack_b, NULL);
		if (duplicate(argv + 1) == 1)
			ft_error_p(stack_a, stack_b, NULL);
	}
	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		if (!split_args)
			ft_error_p(stack_a, stack_b, NULL);
		if (limits(split_args) == 1 || duplicate(split_args) == 1)
		{
			free_split(split_args);
			ft_error_p(stack_a, stack_b, NULL);
		}
	}
	free_split(split_args);
}

void	init_list_split(char **split_args, t_list **stack)
{
	if (!split_args || !split_args[0])
		return ;
	create_stack(split_args, stack, 1);
}

void	init_list(int argc, char **argv, t_list **stack)
{
	char	**split_args;
	int		j;

	j = 0;
	*stack = NULL;
	if (argc > 2)
		create_stack(argv + 1, stack, 1);
	else if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		if (!split_args)
			ft_error_p(NULL, NULL, split_args);
		init_list_split(split_args, stack);
		while (split_args[j])
			free(split_args[j++]);
		free(split_args);
	}
}

void	create_stack(char **argv, t_list **stack, int start_index)
{
	t_list	*new;
	int		i;
	int		index;

	i = 0;
	index = start_index;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi_swap(argv[i]));
		new->index = index;
		ft_lstadd_back(stack, new);
		i++;
		index++;
	}
}
