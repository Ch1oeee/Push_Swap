/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:24:22 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/14 15:57:30 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = int_len(n);
	array = ft_calloc((len + 1), sizeof(char));
	if (!array)
		return (NULL);
	if (n < 0)
	{
		array[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		array[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (array);
}

// int	main(void)
// {
// 	int	n = 45689;
// 	ft_itoa(n);
// }