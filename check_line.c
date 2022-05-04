/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:22:52 by larobbie          #+#    #+#             */
/*   Updated: 2022/05/04 19:23:26 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line(t_game *g)
{
	int	x;
	int	y;
	int	count;
	int	j;

	x = g->player->pos.i;
	y = g->player->pos.j;
	count = 0;
	j = 0;
	while (g->map->map[x][j])
	{
		if (g->map->map[x][j] == 'P' && j != y)
			g->map->map[x][j] = '0';
		j++;
	}
}
