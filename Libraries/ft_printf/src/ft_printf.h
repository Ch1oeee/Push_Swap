/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 01:26:05 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/26 01:26:07 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

int		ft_print_u(unsigned int n);
int		ft_print_str(char *str);
int		ft_print_c(char c);
int		ft_print_i_and_d(int n);
int		ft_print_x(unsigned long n, const char format);
int		ft_print_p(unsigned long n);
int		ft_print_format(const char *format, va_list args, int i, ...);
int		ft_printf(const char *format, ...);
int		ft_print_per(char c);

#endif