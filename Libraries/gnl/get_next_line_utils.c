/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:24:38 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/26 17:18:48 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		len_s1;
	int		len_s2;
	int		i ;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = ft_calloc(sizeof(char), (len_s1 + len_s2 + 1));
	if (!new_str)
		return (NULL);
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		new_str[i + len_s1] = s2[i];
		i++;
	}
	return (new_str);
}

char	*free_join(char *content, char *buffer)
{
	char	*new;

	new = ft_strjoin(content, buffer);
	if (!new)
		return (NULL);
	free(content);
	return (new);
}
