/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:07:11 by larobbie          #+#    #+#             */
/*   Updated: 2022/05/04 19:21:18 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*parse(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *)malloc(sizeof(char) * dist(buffer) + 1);
	if (!line)
		return (NULL);
	while (i < dist(buffer))
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_new(char *buffer)
{
	int		i;
	char	*new;
	int		j;

	i = dist(buffer);
	j = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(buffer + i) + 1);
	if (!new)
	{
		if (buffer != NULL)
			free(buffer);
		return (NULL);
	}
	while (buffer[i])
	{
		new[j] = buffer[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(buffer);
	return (new);
}

char	*read_line(int fd, char *buffer)
{
	char	line[BUFFER_SIZE + 1];
	int		len;

	len = 1;
	while (len && n_not_in(buffer))
	{
		len = (int)read(fd, line, BUFFER_SIZE);
		if (len == -1)
			return (NULL);
		line[len] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = parse(buffer);
	if (!line || !ft_strlen(line))
	{
		free(line);
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = get_new(buffer);
	return (line);
}
