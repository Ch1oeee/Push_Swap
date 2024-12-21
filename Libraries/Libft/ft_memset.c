/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:54:09 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/09 10:11:00 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*dest;

	dest = ((char *)s);
	i = 0;
	while (i < n)
	{
		dest[i] = ((char)c);
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	s[] = "hello";
// 	int	c = 'k';
// 	size_t n = 8;
// 	ft_memset(s, c, n);
// 	// printf("%p\n", memset(s,c,n));
// 	return (0);
// }
