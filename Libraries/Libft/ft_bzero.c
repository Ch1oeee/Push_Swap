/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:28:08 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/09 10:09:59 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dest;

	dest = ((char *)s);
	i = 0;
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char s[] = "Bonjour";
// 	size_t n = 4;
// 	ft_bzero(s, n);
// 	return (0);
// }
