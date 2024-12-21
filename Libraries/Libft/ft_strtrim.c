/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:07:36 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/11 17:40:49 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	i;
	size_t	end;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[end - 1]) && end > i)
		end--;
	new_str = malloc(sizeof(char) * (end - i + 1));
	if (!new_str)
		return (NULL);
	j = 0;
	while (i < end)
	{
		new_str[j] = s1[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

// int main(void)
// {
	// char s1[] = "bozo chloe bozo";
	// char set[] = "test";
	// char *result = ft_strtrim("   xxx   xxx", " x");
	// printf ("%s\n", result);
	// free(result);
	// printf ("%s\n", ft_strtrim("bozo chloe bozo", ""));
// }
