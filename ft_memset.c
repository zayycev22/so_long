/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:09:04 by larobbie          #+#    #+#             */
/*   Updated: 2022/05/04 19:18:32 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len > 0)
	{
		*p = (unsigned char)c;
		p++;
		len--;
	}
	return (b);
}

void	mem(t_game *g)
{
	g->back = malloc(sizeof(t_background));
	g->collect = malloc(sizeof(t_collect));
	g->exit = malloc(sizeof(t_exit));
	g->player = malloc(sizeof(t_player));
	g->wall = malloc(sizeof(t_wall));
	ft_memset(g->back, 0, sizeof(t_background));
	ft_memset(g->collect, 0, sizeof(t_collect));
	ft_memset(g->exit, 0, sizeof(t_exit));
	ft_memset(g->player, 0, sizeof(t_player));
	ft_memset(g->wall, 0, sizeof(t_wall));
	zero(g);
}

void	zero(t_game *g)
{
	g->collect->count = 0;
	g->exit->count = 0;
	g->player->count = 0;
	g->player->pic.name = "pic/down-2.xpm";
}
