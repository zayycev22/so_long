/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:18:09 by larobbie          #+#    #+#             */
/*   Updated: 2022/05/04 19:18:13 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static int	count_n(long n)
{
	int	cnt;

	cnt = 0;
	if (n == -2147483648)
		return (11);
	if (n < 1)
	{
		cnt++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static void	reverse(char *a)
{
	size_t	i;
	char	c;

	i = 0;
	while (i < ft_strlen(a) / 2)
	{
		c = a[i];
		a[i] = a[ft_strlen(a) - 1 - i];
		a[ft_strlen(a) - 1 - i] = c;
		i++;
	}
}

static int	checks(long *n, char *s, int *i)
{
	int		check;
	int		check2;

	check = 0;
	check2 = 0;
	if (*n < 0)
	{
		if (*n == -2147483648)
		{
			*n = *n + 1;
			check2 = 1;
		}
		s[count_n(*n) - 1] = '-';
		*n = *n * -1;
		check = 1;
	}
	if (*n == 0)
	{
		s[0] = '0';
		*i = 1;
	}
	return (check + check2);
}

static char	*get_full(long *tmp, char *s, int *i)
{
	int	j;

	j = *i;
	while (*tmp > 0)
	{
		s[j] = (char )((*tmp % 10) + '0');
		*tmp /= 10;
		j++;
	}
	*i = j;
	return (s);
}

char	*ft_itoa(long n)
{
	char		*s;
	int			i;
	int			check;
	long		tmp;

	tmp = n;
	s = (char *) malloc(sizeof(char) * count_n(n) + 1);
	if (!s)
		return (NULL);
	i = 0;
	check = checks(&tmp, s, &i);
	s = get_full(&tmp, s, &i);
	if (check > 0)
	{
		if (check > 1)
			s[0] = '8';
		i++;
	}
	s[i] = '\0';
	reverse(s);
	s[i] = '\0';
	return (s);
}
