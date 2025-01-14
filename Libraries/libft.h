/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:36:55 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/14 14:54:33 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int			content;
	int			index;
	int			target_value;
	int			target_index;
	int			cost;
	struct s_list	*next;
}	t_list;

int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *str, char const *caracters);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *str, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);



#endif
