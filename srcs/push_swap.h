/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:30:03 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/17 15:25:35 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include "../Libraries/libft.h"

int		is_number(char *str);
void	ft_error_p(void);
int		ft_atoi_swap(const char *str);
int		limits(char **argv);
int		duplicate(char **argv);
void	check_args(int argc, char **argv);
void	init_list_split(char **split_args, t_list **stack);
void	init_list(int argc, char **argv, t_list **stack);
int		swap(t_list **stack);
int		sa(t_list **stack_a, int true);
int		sb(t_list **stack_b, int true);
int		ss(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		rotate(t_list **stack);
int		ra(t_list **stack_a, int true);
int		rb(t_list **stack_b, int true);
int		reverse_rotate(t_list **stack);
int		rra(t_list **stack_a, int true);
int		rrb(t_list **stack_b, int true);
int		algo_three(t_list **stack_a);
int		algo_five(t_list **stack_a, t_list **stack_b);
t_list	*find_biggest(t_list *stack);
t_list	*find_smallest(t_list *stack);
int		get_mediane(t_list **stack_a);
void	sort_list(int *list_element, int size);
void	med_supp(t_list **stack_a, t_list **stack_b);
void	gen_algo(t_list **stack_a, t_list **stack_b);
void	calculate_move_cost(t_list **stack_a, t_list **stack_b);
void	gen_rotate(t_list **stack_a, t_list **stack_b);
t_list	*smallest_cost(t_list **stack_b);
void	update_target_index_rra(t_list *smallest_cost_node, t_list *stack_a);
void	update_target_index_ra(t_list *smallest_cost_node, t_list *stack_a);
void	update_smallest_index_rrb(t_list *smallest_cost_node, t_list *stack_b);
void	update_smallest_index_rb(t_list *smallest_cost_node, t_list *stack_b);
void	debug_stack(t_list *stack, const char *stack_name);

void find_closest_values(t_list **stack_a, t_list **stack_b);
void closest_value_a(t_list **stack_a, t_list **stack_b);
int calculate_individual_cost(int index, int size);
void calculate_move_cost(t_list **stack_a, t_list **stack_b);
int calculate_cost(t_list *node, t_list *stack_a, int size_a);

















#endif