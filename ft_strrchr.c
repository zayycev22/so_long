/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:07:56 by larobbie          #+#    #+#             */
/*   Updated: 2022/05/04 19:19:54 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	char	i;
	char	*str;
	int		j;

	j = 0;
	i = (char)c;
	str = (char *)s;
	while (str[j])
		j++;
	while (j >= 0)
	{
		if (str[j] == i)
			return (&str[j]);
		j--;
	}
	return (NULL);
}
