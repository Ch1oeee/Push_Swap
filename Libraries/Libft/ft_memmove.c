/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:25:53 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/08 09:25:55 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;

	tmp = ((char *)src);
	if (dest < src)
		dest = ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			n--;
			((char *)dest)[n] = tmp[n];
		}
	}
	return (dest);
}

// int main( void )
// {
//     char s[50] = "Bonjour les enfants";
//     memmove( s+2 , s , 4 );
//     printf("%s\n",s);
// 	ft_memmove( s+2 , s , 4 );
//     printf("%s\n",s);
//     return 0;
// }