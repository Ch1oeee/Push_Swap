/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:13:09 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/13 09:42:42 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new_str;
	size_t	str_len;

	i = start;
	j = 0;
	str_len = ft_strlen(str);
	if (!str)
		return (NULL);
	if (start > str_len)
		return (ft_strdup(""));
	if (len >= str_len)
		len = str_len - start;
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (str[i] && j < len)
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

// int	main(void)
// {
// 	char	str[] = "0123456789";
// 	unsigned int	start = 9;
// 	size_t len =  10;
// 	char	*result = ft_substr(str, start, len);
// 	printf("result = \"%s\"\n", result);
// 	return (0);
// }