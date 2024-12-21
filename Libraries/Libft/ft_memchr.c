/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:13:00 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/08 13:13:01 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

// int main (void) 
// {
// 	char	s[] = "hello tout le monde";
// 	int	c = 'o';
// 	printf("%p\n", memchr(s, c, 5));
// 	printf("%p\n", ft_memchr(s, c, 5));

// }