/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:06:38 by larobbie          #+#    #+#             */
/*   Updated: 2022/05/04 19:06:40 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_all(t_game *g)
{
	free(g);
	exit (1);
}

int	rewrite_map(t_game *g)
{
	mlx_clear_window(g->surface.mlx, g->surface.mlx_win);
	draw_images(g);
	return (0);
}
