/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:56:37 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/26 01:25:13 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_print_format(const char *format, va_list args, int i, ...)
{
	int	len;

	len = 0;
	if (format[i] == 'u')
		len += ft_print_u(va_arg(args, unsigned int));
	else if (format[i] == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (format[i] == 'p')
		len += ft_print_p(va_arg(args, unsigned long));
	else if (format[i] == 'd' || format[i] == 'i')
		len += ft_print_i_and_d(va_arg(args, int));
	else if (format[i] == 'X' || format[i] == 'x')
		len += ft_print_x((va_arg(args, unsigned int)), format[i]);
	else if (format[i] == '%')
		len += ft_print_c('%');
	else if (format[i] == 'c')
		len += ft_print_c(va_arg(args, int));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_print_c(format[i]);
			len++;
		}
		else
		{
			i++;
			len += ft_print_format(format, args, i);
		}
		i++;
	}
	va_end(args);
	return (len);
}

// int main (void)
// {
// 	printf(" NULL %s NULL ", "");
// 	ft_printf("NULL %s NULL ", "");
// 	return (0);
// }