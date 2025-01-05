/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:24:30 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/26 01:25:41 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_print_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_print_u(n / 10);
		ft_print_u(n % 10);
	}
	if (n <= 9)
		ft_print_c('0' + n);
	i++;
	return (i);
}
