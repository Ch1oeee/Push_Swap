/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:28:24 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/09 10:09:42 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*lastone;

	lastone = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			lastone = ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return (((char *)&str[i]));
	return (lastone);
}

// int	main(void)
// {
// 	const char *str = "Hello World";
// 	// char c = "";
// 	char *result = ft_strrchr(str, 0);
// 			printf("Reponse %s\n", result);

// 	result = strrchr(str, 0);
// 			printf("Reponse %s\n", result);
// }