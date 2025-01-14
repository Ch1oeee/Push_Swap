/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:30:06 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/14 14:37:11 by cmontaig         ###   ########.fr       */
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

		*stack_a = NULL;
		*stack_b = NULL;
		init_list(argc, argv, stack_a);

		if (argc == 4)
			algo_three(stack_a);
		else if (argc == 6)
			algo_five(stack_a, stack_b);
		else
		{
			gen_algo(stack_a, stack_b);
		}

		printf("Stack A\n");
		print_stack(*stack_a);

		printf("Stack B\n");
		print_stack(*stack_b);
 
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
		free(stack_a);
		free(stack_b);
	}
	return (0);
}
