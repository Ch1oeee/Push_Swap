/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:33:37 by cmontaig          #+#    #+#             */
/*   Updated: 2024/12/18 18:15:05 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned long n, const char format)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_print_x(n / 16, format);
		len += ft_print_x(n % 16, format);
	}
	else
	{
		if (format == 'x')
			len += ft_print_c("0123456789abcdef"[n % 16]);
		else
			len += ft_print_c("0123456789ABCDEF"[n % 16]);
	}
	return (len);
}

int	ft_print_p(unsigned long n)
{
	int	len;

	len = 0;
	if (!n)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	len += ft_print_x(n, 'x');
	return (len);
}
