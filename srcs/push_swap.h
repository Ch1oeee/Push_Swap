/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:30:03 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/05 19:36:22 by cmontaig         ###   ########.fr       */
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
int		reverse_rotate(t_list **stack);
int		rra(t_list **stack_a, int true);
int		rrb(t_list **stack_b, int true);

#endif