/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:30:06 by cmontaig          #+#    #+#             */
/*   Updated: 2024/12/28 17:41:47 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../Libraries/Libft/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_number(char *str)
{
	int i;
	int sign_count;

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
	while(argv[i])
	{
		if(!is_number(argv[i]))
			return (1);
		ft_atoi_swap(argv[i]);
		i++;
	}
	return (0);
}



int main (int argc, char **argv)
{
	int	i = 1;
	
	if (argc > 2)
	{
		if(limits(argv + 1) == 1)
			ft_error_p();

		while (argv[i])
		{
			printf("%d\n", ft_atoi_swap(argv[i]));
			i++;
		}
	}
	return (0);
}