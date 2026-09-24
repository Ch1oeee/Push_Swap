/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:55:25 by cmontaig          #+#    #+#             */
/*   Updated: 2025/02/26 15:02:57 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libraries/libft.h"

int	is_number(char *str)
{
	int	i;
	int	sign_count;

	i = 0;
	sign_count = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		sign_count++;
		i++;
	}
	if (sign_count > 1)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_error_p(t_list **stack_a, t_list **stack_b, char **split_args)
{
	if (split_args)
		free_split(split_args);
	if (stack_a)
		free_stacks(stack_a, stack_b);
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}

long int	ft_atoi_swap(const char *str)
{
	long int	result;
	int			sign;
	int			i;

	if (!str)
		return (ft_putstr_fd("Error\n", 1), ERROR);
	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		if (!str[i + 1])
			return (ERROR);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return ((result * sign));
}

int	limits(char **argv)
{
	int			i;
	long int	nb;

	i = 0;
	nb = ft_atoi_swap(argv[i]);
	while (argv[i])
	{
		nb = ft_atoi_swap(argv[i]);
		if (!is_number(argv[i]))
			return (1);
		if (nb > INT_MAX || nb < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	duplicate(char **argv)
{
	int	i;
	int	j;
	int	num_i;
	int	num_j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		num_i = ft_atoi_swap(argv[i]);
		while (argv[j])
		{
			num_j = ft_atoi_swap(argv[j]);
			if (num_i == num_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
