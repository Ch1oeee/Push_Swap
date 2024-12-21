/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:01:56 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/13 06:50:19 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	word_len(char const *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *str, char c)
{
	char	**words;
	size_t	i;
	size_t	length;
	size_t	j;

	i = 0;
	j = 0;
	words = ft_calloc((word_count(str, c) + 1), sizeof(char *));
	if (!words)
		return (NULL);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
		{
			length = word_len(&str[i], c);
			words[j] = ft_substr(str, i, length);
			j++;
			i += length;
		}
	}
	return (words);
}

// int	main(void)
// {
// 	char	str[] = "Fizzyclap en vacances a la Fizzyplage";
// 	// char	str[] = "    njsnjvd     nsjsnjk  cd    ";
// 	char	c = ' ';
// 	// printf("%zu\n", word_count(str, c));
// 	ft_split(str, c);
// 	return (0);
// }
