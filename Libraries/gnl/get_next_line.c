/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:24:35 by cmontaig          #+#    #+#             */
/*   Updated: 2025/01/26 17:18:31 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

char	*one_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*lines_after(char *buffer)
{
	int		i;
	int		j;
	char	*line_after;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line_after = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!line_after)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line_after[j++] = buffer[i++];
	line_after[j] = '\0';
	free(buffer);
	return (line_after);
}

char	*read_txt(int fd, char *txt)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		txt = free_join(txt, buffer);
		if (!txt)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (txt);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4096)
		return (NULL);
	buffer[fd] = read_txt(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = one_line(buffer[fd]);
	buffer[fd] = lines_after(buffer[fd]);
	return (line);
}

int	gnl(int fd)
{
	char	*line;

	if (fd < 0)
	{
		perror("Erreur : descripteur de fichier invalide");
		return (1);
	}
	(line = get_next_line(fd));
	while (line)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
