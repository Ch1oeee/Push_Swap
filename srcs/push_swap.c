/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:30:06 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/05 19:40:24 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../Libraries/libft.h"

void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("Content: %d, Index: %d\n", stack->content, stack->index);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_list **stack_a = NULL;
	t_list **stack_b = NULL;

	if (argc >= 2)
	{
		check_args(argc, argv);
		stack_a = malloc(sizeof(t_list *));
		stack_b = malloc(sizeof(t_list *));
		if (!stack_a || !stack_b)
			ft_error_p();
		init_list(argc, argv, stack_a);

		sa(stack_a, 0);
		printf("Stack A\n");
		print_stack(*stack_a);

		free(stack_a);
		free(stack_b);
	}
	return (0);
}
