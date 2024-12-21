/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:19:57 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/11 11:06:33 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		len_s1;
	int		len_s2;
	size_t	i ;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = ft_calloc(sizeof(char), (len_s1 + len_s2 + 1));
	if (!new_str)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		new_str[i + len_s1] = s2[i];
		i++;
	}
	return (new_str);
}
// int	main(void)
// {
// 	char s1[] = "Tripouille";
// 	char s2[] = "42";
// 	// printf("%s\n",ft_strjoin(s1, s2));
// 	ft_strjoin(s1, s2);
// 	return (0);
// }