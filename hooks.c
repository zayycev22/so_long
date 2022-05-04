/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:06:26 by larobbie          #+#    #+#             */
/*   Updated: 2022/05/04 19:48:42 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	go_up(t_game *g)
{
	int	x;
	int	y;

	x = g->player->pos.i;
	y = g->player->pos.j;
	if (g->map->map[x - 1][y] != '1')
	{
		if ((g->map->map[x - 1][y] == '0' || g->map->map[x - 1][y] == 'C') && \
			g->map->map[x - 1][y] != 'E')
		{
			if (g->map->map[x - 1][y] == 'C')
				g->collect->count--;
			g->map->map[x - 1][y] = 'P';
			g->map->map[x][y] = '0';
			g->player->moves++;
		}
		if (g->map->map[x - 1][y] == 'E' && g->collect->count == 0)
			win(g);
		printnb(g->player->moves);
		ft_putchar_fd('\n', 0);
		g->player->pic.name = "pic/up-2.xpm";
		g->player->pos.i--;
	}
}

static void	go_down(t_game *g)
{
	int	x;
	int	y;

	x = g->player->pos.i;
	y = g->player->pos.j;
	if (g->map->map[x + 1][y] != '1')
	{
		if ((g->map->map[x + 1][y] == '0' || g->map->map[x + 1][y] == 'C') && \
			g->map->map[x + 1][y] != 'E')
		{
			if (g->map->map[x + 1][y] == 'C')
				g->collect->count--;
			g->map->map[x + 1][y] = 'P';
			g->map->map[x][y] = '0';
			g->player->moves++;
			g->player->pos.i++;
			printnb(g->player->moves);
			g->player->pic.name = "pic/down-2.xpm";
			ft_putchar_fd('\n', 0);
		}
		if (g->map->map[x + 1][y] == 'E' && !g->collect->count)
			win(g);
	}
}

static void	go_left(t_game *g)
{
	int	x;
	int	y;

	x = g->player->pos.i;
	y = g->player->pos.j;
	if (g->map->map[x][y - 1] != '1')
	{
		if ((g->map->map[x][y - 1] == '0' || g->map->map[x][y - 1] == 'C') && \
			g->map->map[x][y - 1] != 'E')
		{
			if (g->map->map[x][y - 1] == 'C')
				g->collect->count--;
			g->map->map[x][y - 1] = 'P';
			g->map->map[x][y] = '0';
			g->player->moves++;
			g->player->pos.j--;
			printnb(g->player->moves);
			g->player->pic.name = "pic/left-2.xpm";
			ft_putchar_fd('\n', 0);
		}
		if (g->map->map[x][y - 1] == 'E' && !g->collect->count)
			win(g);
	}
}

static void	go_right(t_game *g)
{
	int	x;
	int	y;

	x = g->player->pos.i;
	y = g->player->pos.j;
	if (g->map->map[x][y + 1] != '1')
	{
		if ((g->map->map[x][y + 1] == '0' || g->map->map[x][y + 1] == 'C') && \
			g->map->map[x][y + 1] != 'E')
		{
			if (g->map->map[x][y + 1] == 'C')
				g->collect->count--;
			g->map->map[x][y + 1] = 'P';
			g->map->map[x][y] = '0';
			g->player->moves++;
			g->player->pos.j++;
			g->player->pic.name = "pic/right-2.xpm";
			printnb(g->player->moves);
			ft_putchar_fd('\n', 0);
		}
		if (g->map->map[x][y + 1] == 'E' && !g->collect->count)
			win(g);
	}
}

int	key_event(int code, t_game *g)
{
	if (code == 13)
		go_up(g);
	if (code == 1)
		go_down(g);
	if (code == 0)
		go_left(g);
	if (code == 2)
		go_right(g);
	check_line(g);
	if (code == 53)
		free_all(g);
	return (0);
}
