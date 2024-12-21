/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:46:55 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/06 17:46:57 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i <= len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && i + j <= len - 1)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {

// 	char big[] = "Bozoland c'est la maison de Robin";
// 	char little[] = "hg ";
// 	printf("%s\n", ft_strnstr(big, little, 20));
// 	// printf("%s\n", strnstr(big, little, 20));

// 	return (0);
// 	// char *ntm;

// 	// ntm = ft_strnstr("Bonjour", "Bon", 0);
// 	// if (!ntm)
// 	// 	printf("(null)\n");
// 	// else
// 	// 	printf("%s\n", ntm);
// }