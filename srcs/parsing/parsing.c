/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:55:25 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/03 12:00:26 by cmontaig         ###   ########.fr       */
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

void	ft_error_p(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	ft_atoi_swap(const char *str)
{
	long	result;
	int		sign;
	int		i;

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
			ft_error_p();
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		ft_error_p();
	return ((int)(result * sign));
}

int	limits(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (1);
		ft_atoi_swap(argv[i]);
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
