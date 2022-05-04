/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:07:30 by larobbie          #+#    #+#             */
/*   Updated: 2022/05/04 19:21:06 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_game *g)
{
	g->player->moves++;
	printnb(g->player->moves);
	ft_putstr_fd("\nwin\n", 0);
	mlx_clear_window(g->surface.mlx, g->surface.mlx_win);
	exit (0);
}

static void	put_image(t_game *g)
{
	int	x;

	x = 40;
	g->player->pic.img = mlx_xpm_file_to_image(g->surface.mlx, \
		g->player->pic.name, &x, &x);
	g->collect->pic.img = mlx_xpm_file_to_image(g->surface.mlx, \
		"pic/bomb.xpm", &x, &x);
	g->exit->pic.img = mlx_xpm_file_to_image(g->surface.mlx, \
		"pic/door.xpm", &x, &x);
	g->wall->pic.img = mlx_xpm_file_to_image(g->surface.mlx, \
		"pic/wall.xpm", &x, &x);
	g->back->pic.img = mlx_xpm_file_to_image(g->surface.mlx, \
		"pic/background.xpm", &x, &x);
}

static void	draw_images_1(t_game *g, int x, int y)
{
	if (g->map->map[x][y] == '1')
		mlx_put_image_to_window(g->surface.mlx, g->surface.mlx_win,
			g->wall->pic.img, y * 40, x * 40);
	if (g->map->map[x][y] == '0')
		mlx_put_image_to_window(g->surface.mlx, g->surface.mlx_win,
			g->back->pic.img, y * 40, x * 40);
	if (g->map->map[x][y] == 'P')
	{
		mlx_put_image_to_window(g->surface.mlx, g->surface.mlx_win,
			g->player->pic.img, y * 40, x * 40);
		g->player->pos.i = x;
		g->player->pos.j = y;
	}
	if (g->map->map[x][y] == 'C')
		mlx_put_image_to_window(g->surface.mlx, g->surface.mlx_win,
			g->collect->pic.img, y * 40, x * 40);
	if (g->map->map[x][y] == 'E')
		mlx_put_image_to_window(g->surface.mlx, g->surface.mlx_win,
			g->exit->pic.img, y * 40, x * 40);
}

void	draw_images(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	put_image(g);
	while (x < g->map->n)
	{
		y = 0;
		while (y < g->map->m)
		{
			draw_images_1(g, x, y);
			y++;
		}
		x++;
	}
}

void	so_long(t_game *g)
{
	g->surface.mlx = mlx_init();
	g->surface.mlx_win = mlx_new_window(g->surface.mlx, \
		g->map->m * 40, g->map->n * 40, "game");
	put_image(g);
	draw_images(g);
	mlx_hook(g->surface.mlx_win, 02, 0, key_event, g);
	mlx_hook(g->surface.mlx_win, 17, 0, free_all, g);
	mlx_loop_hook(g->surface.mlx, rewrite_map, g);
	mlx_loop(g->surface.mlx);
}
