/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:07:18 by larobbie          #+#    #+#             */
/*   Updated: 2022/05/04 19:21:11 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (c == NULL)
		return (0);
	while (c[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*len;
	size_t		i;
	size_t		len1;

	i = 0;
	len1 = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!len)
		return (NULL);
	while (s1[len1])
		len[i++] = ((char *)s1)[len1++];
	while (*s2 != '\0')
		len[i++] = (*(char *)s2++);
	len[i] = '\0';
	free(s1);
	return (len);
}

int	n_not_in(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	dist(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	if (s[i] == '\n')
		i++;
	return (i);
}
