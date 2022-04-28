/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:38:22 by sergejleski       #+#    #+#             */
/*   Updated: 2022/04/28 23:00:42 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	check_map_4(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (j < g->map->n)
	{
		i = 0;
		while (i < g->map->m)
		{
			if (g->map->map[j][i] == 'P')
				g->player.count++;
			if (g->map->map[j][i] == 'C')
				g->collect.count++;
			if (g->map->map[j][i] == 'E')
				g->exit.count++;
			i++;
		}
		j++;
	}
	if (g->player.count != 1 || g->collect.count < 1 || g->exit.count < 1)
		error_exit();
}

void	check_map_3(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (j < g->map->n)
	{
		i = 0;
		while (i < g->map->m)
		{
			if (g->map->map[j][i] != '1' && g->map->map[j][i] != '0'
				&& g->map->map[j][i] != 'P' && g->map->map[j][i] != 'C'
				&& g->map->map[j][i] != 'E')
				error_exit();
			i++;
		}
		j++;
	}
	check_map_4(g);
}

void	check_map_2(t_game *g)
{
	int	l;

	l = -1;
	while (l++ < g->map->n - 1)
	{
		if (g->map->map[l][0] != '1' || g->map->map[l][g->map->m - 1] != '1')
			error_exit();
	}
	l = -1;
	while (l++ < g->map->m - 1)
	{
		if (g->map->map[0][l] != '1' || g->map->map[g->map->n - 1][l] != '1')
			error_exit();
	}
	check_map_3(g);
}

void	check_map_1(t_game *g)
{
	int	l;

	l = 0;
	g->map->m = map_len(g->map->map[l]);
	while (l++ < g->map->n - 1)
	{
		if (g->map->m != map_len(g->map->map[l]))
			error_exit();
	}
	check_map_2(g);
}
