/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:01:56 by cmontaig          #+#    #+#             */
/*   Updated: 2024/12/30 17:13:26 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	separators(char c, char const *caracters)
{
	int	i;

	i = 0;
	while (caracters[i])
	{
		if (caracters[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	word_count(char const *s, char const *caracters)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && separators(s[i], caracters) && s[i])
			i++;
		if (s[i])
			count++;
		while (!separators(s[i], caracters) && s[i])
			i++;
	}
	return (count);
}

static int	word_len(char const *str, char const *caracters)
{
	size_t	len;

	len = 0;
	while (str[len] && !separators(str[len], caracters))
		len++;
	return (len);
}

char	**ft_split(char const *str, char const *caracters)
{
	char	**words;
	size_t	i;
	size_t	length;
	size_t	j;

	i = 0;
	j = 0;
	words = ft_calloc((word_count(str, caracters) + 1), sizeof(char *));
	if (!words)
		return (NULL);
	while (str[i])
	{
		while (str[i] && separators(str[i], caracters) && str[i])
			i++;
		if (str[i] && !separators(str[i], caracters))
		{
			length = word_len(&str[i], caracters);
			words[j] = ft_substr(str, i, length);
			j++;
			i += length;
		}
	}
	return (words);
}
