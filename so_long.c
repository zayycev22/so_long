/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:39:07 by sergejleski       #+#    #+#             */
/*   Updated: 2022/04/28 22:59:58 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_s_y(char *a)
{
	char	*s;
	int		i;
	int		fd;

	i = 0;
	fd = open(a, O_RDONLY);
	if (fd < 0)
		error_exit();
	s = get_next_line(fd);
	while (s)
	{
		i++;
		free(s);
		s = get_next_line(fd);
	}
	return (i);
}

void	check_map(t_game *g, char *argv)
{
	char	*s;
	int		i;
	int		fd;

	i = 0;
	g->map->n = find_s_y(argv);
	fd = open(argv, O_RDONLY);
	g->map = malloc(sizeof(char *) * g->map->n);
	if (fd == -1 || !g->map || g->map->n < 3)
		error_exit();
	s = get_next_line(fd);
	while (i < g->map->n)
	{
		g->map[i] = s;
		i++;
		s = get_next_line(fd);
	}
	i = 0;
	close(fd);
	check_map_1(g);
}

static void	check_format(char *str)
{
	char	*s;

	s = ft_strrchr(str, '.');
	if (s == NULL || (ft_strncmp(s + 1, "ber", 4) != 0))
		error_exit();
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error_exit();
	check_format(argv[1]);
	game = malloc(sizeof(t_game));
	ft_memset(game, 0, sizeof(t_game));
	check_map(game, argv[1]);
	so_long(game);
	exit (0);
}
